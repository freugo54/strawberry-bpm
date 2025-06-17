#ifndef WIDGETS_PLAYLIST_H
#define WIDGETS_PLAYLIST_H

#include <QWidget>

class QTreeView;

namespace Models {
class PlaylistModel;
}

namespace Widgets {

class Playlist : public QWidget {
  Q_OBJECT

 public:
  explicit Playlist(QWidget *parent = nullptr);

 private:
  QTreeView *m_view;
  Models::PlaylistModel *m_model;
};

}  // namespace Widgets

#endif  // WIDGETS_PLAYLIST_H

