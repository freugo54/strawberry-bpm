#include "playlist.h"
#include <QTableView>
#include <QVBoxLayout>

Playlist::Playlist(QWidget* parent)
    : QWidget(parent),
      m_model(new TrackModel(this)),
      m_view(new QTableView(this))
{
    QVBoxLayout* layout = new QVBoxLayout(this);
    layout->addWidget(m_view);
    setLayout(layout);

    m_view->setModel(m_model);
    m_view->setSelectionBehavior(QAbstractItemView::SelectRows);
    m_view->setSelectionMode(QAbstractItemView::SingleSelection);
    m_view->setSortingEnabled(true);

    loadDemoTracks();
}

void Playlist::loadDemoTracks() {
    std::vector<Track> demoTracks;

    Track t1;
    t1.setTitle("Track One");
    t1.setBpm(120.5f);
    demoTracks.push_back(t1);

    Track t2;
    t2.setTitle("Track Two");
    t2.setBpm(95.2f);
    demoTracks.push_back(t2);

    Track t3;
    t3.setTitle("Track Three");
    t3.setBpm(132.7f);
    demoTracks.push_back(t3);

    m_model->setTr_
