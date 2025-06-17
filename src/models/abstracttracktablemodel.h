#ifndef MODELS_ABSTRACTTRACKTABLEMODEL_H
#define MODELS_ABSTRACTTRACKTABLEMODEL_H

#include <QAbstractTableModel>

namespace Models {

class AbstractTrackTableModel : public QAbstractTableModel {
  Q_OBJECT

 public:
  explicit AbstractTrackTableModel(QObject *parent = nullptr) : QAbstractTableModel(parent) {}
  ~AbstractTrackTableModel() override = default;

  // Dummy-Zugriff – im echten Modell wird das dynamisch geladen
  int rowCount(const QModelIndex & = QModelIndex()) const override { return 2; }
  int columnCount(const QModelIndex & = QModelIndex()) const override { return 5; }

  QVariant data(const QModelIndex &, int = Qt::DisplayRole) const override { return {}; }

  // Füge hier eine Dummy-Funktion hinzu, die z. B. trackAt(index) zurückgeben könnte
};

}  // namespace Models

#endif  // MODELS_ABSTRACTTRACKTABLEMODEL_H
