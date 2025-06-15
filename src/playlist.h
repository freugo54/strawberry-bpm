#ifndef PLAYLIST_H
#define PLAYLIST_H

#include <QWidget>
#include "trackmodel.h"

class QTableView;

class Playlist : public QWidget {
    Q_OBJECT
public:
    explicit Playlist(QWidget* parent = nullptr);
    void loadDemoTracks();

private:
    TrackModel* m_model;
    QTableView* m_view;
};

#endif // PLAYLIST_H
