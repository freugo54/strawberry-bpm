#ifndef TRACKMODEL_H
#define TRACKMODEL_H

#include <QAbstractTableModel>
#include "track.h"
#include <vector>

class TrackModel : public QAbstractTableModel {
    Q_OBJECT
public:
    enum Column {
        Title = 0,
        Bpm,
        ColumnCount
    };

    explicit TrackModel(QObject* parent = nullptr);

    int rowCount(const QModelIndex& parent = QModelIndex()) const override;
    int columnCount(const QModelIndex& parent = QModelIndex()) const override;
    QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const override;
    Qt::ItemFlags flags(const QModelIndex& index) const override;

    void setTracks(const std::vector<Track>& tracks);

private:
    std::vector<Track> m_tracks;
};

#endif // TRACKMODEL_H

