#ifndef MODELS_TRACKMETADATAMODEL_H
#define MODELS_TRACKMETADATAMODEL_H

#include "abstracttracktablemodel.h"

namespace Models {

class TrackMetadataModel : public AbstractTrackTableModel {
  Q_OBJECT

 public:
  explicit TrackMetadataModel(QObject *parent = nullptr);
  ~TrackMetadataModel() override;

  int columnCount(const QModelIndex &parent = QModelIndex()) const override;
  QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
  QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;

  enum Column {
    Title = 0,
    Artist,
    Album,
    Length,
    Bpm,           // NEU
    ColumnCount
  };

  Qt::ItemFlags flags(const QModelIndex &index) const override;

  int BpmColumnIndex() const { return Bpm; }
};

}  // namespace Models

#endif  // MODELS_TRACKMETADATAMODEL_H
