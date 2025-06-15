#include "trackmodel.h"

TrackModel::TrackModel(QObject* parent)
    : QAbstractTableModel(parent)
{
}

int TrackModel::rowCount(const QModelIndex& /*parent*/) const {
    return static_cast<int>(m_tracks.size());
}

int TrackModel::columnCount(const QModelIndex& /*parent*/) const {
    return ColumnCount;
}

QVariant TrackModel::data(const QModelIndex& index, int role) const {
    if (!index.isValid() || role != Qt::DisplayRole)
        return QVariant();

    const Track& track = m_tracks.at(index.row());

    switch (index.column()) {
    case Title:
        return track.title();
    case Bpm:
        return QString::number(track.bpm(), 'f', 1); // eine Nachkommastelle
    default:
        return QVariant();
    }
}

QVariant TrackModel::headerData(int section, Qt::Orientation orientation, int role) const {
    if (role != Qt::DisplayRole || orientation != Qt::Horizontal)
        return QVariant();

    switch (section) {
    case Title:
        return "Title";
    case Bpm:
        return "BPM";
    default:
        return QVariant();
    }
}

Qt::ItemFlags TrackModel::flags(const QModelIndex& index) const {
    if (!index.isValid())
        return Qt::NoItemFlags;

    return Qt::ItemIsEnabled | Qt::ItemIsSelectable;
}

void TrackModel::setTracks(const std::vector<Track>& tracks) {
    beginResetModel();
    m_tracks = tracks;
    endResetModel();
}
