#include "models/trackmodel.h"
#include "core/track.h"

#include <QVariant>
#include <QString>
#include <QModelIndex>

namespace Models {

// Temporäre Dummy-Funktion, um kompilierbaren Zugriff auf einen Track zu ermöglichen
static Core::Track TrackAt(int row) {
  Core::Track dummy;
  dummy.SetTitle(QStringLiteral("Dummy Title"));
  dummy.SetBpm(123.4f);
  return dummy;
}

QVariant TrackMetadataModel::data(const QModelIndex &index, int role) const {
  if (!index.isValid() || role != Qt::DisplayRole) {
    return {};
  }

  const Core::Track &track = TrackAt(index.row());

  switch (index.column()) {
    case 0:
      return track.Title();
    case 1:
      return QString::number(track.Bpm(), 'f', 1);  // 1 Nachkommastelle
    default:
      return {};
  }
}

}  // namespace Models
