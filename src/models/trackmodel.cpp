#include "trackmodel.h"
#include "core/track.h"

namespace Models {

TrackMetadataModel::TrackMetadataModel(QObject *parent)
    : AbstractTrackTableModel(parent) {}

TrackMetadataModel::~TrackMetadataModel() = default;

int TrackMetadataModel::columnCount(const QModelIndex &) const {
  return ColumnCount;
}

QVariant TrackMetadataModel::data(const QModelIndex &index, int role) const {
  if (!index.isValid() || role != Qt::DisplayRole) {
    return {};
  }

  const Core::Track &track = TrackAt(index.row());

  switch (index.column()) {
    case Title:
      return track.Title();
    case Artist:
      return tr("Artist");  // Platzhalter
    case Album:
      return tr("Album");   // Platzhalter
    case Length:
      return tr("3:45");    // Platzhalter
    case Bpm:
      return QString::number(track.Bpm(), 'f', 1);  // NEU
    default:
      return {};
  }
}

QVariant TrackMetadataModel::headerData(int section, Qt::Orientation orientation, int role) const {
  if (role != Qt::DisplayRole || orientation != Qt::Horizontal) {
    return {};
  }

  switch (section) {
    case Title:
      return tr("Title");
    case Artist:
      return tr("Artist");
    case Album:
      return tr("Album");
    case Length:
      return tr("Length");
    case Bpm:
      return tr("BPM");  // NEU
    default:
      return {};
  }
}

Qt::ItemFlags TrackMetadataModel::flags(const QModelIndex &index) const {
  if (!index.isValid()) return Qt::NoItemFlags;
  return Qt::ItemIsSelectable | Qt::ItemIsEnabled;
}

}  // namespace Models
