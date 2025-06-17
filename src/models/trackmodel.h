#ifndef MODELS_TRACKMODEL_H
#define MODELS_TRACKMODEL_H

#include <QAbstractTableModel>

namespace Models {

class TrackMetadataModel : public QAbstractTableModel {
  Q_OBJECT

public:
  explicit TrackMetadataModel(QObject *parent = nullptr) : QAbstractTableModel(parent) {}
  int rowCount(const QModelIndex &parent = QModelIndex()) const override { Q_UNUSED(parent); return 1; }
  int columnCount(const QModelIndex &parent = QModelIndex()) const override { Q_UNUSED(parent); return 2; }
  QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
};

}  // namespace Models

#endif  // MODELS_TRACKMODEL_H
