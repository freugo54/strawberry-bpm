#include "widgets/playlist.h"
#include "models/trackmetadatamodel.h"
#include "models/playlistmodel.h"
#include "core/track.h"

#include <QHeaderView>
#include <QVBoxLayout>

namespace Widgets {

Playlist::Playlist(QWidget *parent)
    : QWidget(parent),
      m_view(new QTreeView(this)),
      m_model(new Models::PlaylistModel(this)) {

  m_view->setModel(m_model);
  m_view->setSelectionMode(QAbstractItemView::ExtendedSelection);
  m_view->setSelectionBehavior(QAbstractItemView::SelectRows);
  m_view->setEditTriggers(QAbstractItemView::NoEditTriggers);
  m_view->setAlternatingRowColors(true);
  m_view->setSortingEnabled(true);
  m_view->header()->setSectionsClickable(true);
  m_view->header()->setStretchLastSection(false);

  // BPM-Spalte sichtbar machen
  int bpmColumn = Models::TrackMetadataModel::Bpm;
  m_view->setColumnHidden(bpmColumn, false);
  m_view->resizeColumnToContents(bpmColumn);

  auto layout = new QVBoxLayout(this);
  layout->addWidget(m_view);
  setLayout(layout);
}

}  // namespace Widgets
