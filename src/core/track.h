#ifndef CORE_TRACK_H
#define CORE_TRACK_H

#include <QString>

namespace Core {

class Track {
public:
  Track();
  ~Track();

  QString Title() const;
  void SetTitle(const QString &title);

  float Bpm() const;
  void SetBpm(float bpm);

  bool operator==(const Track &other) const;

private:
  QString title_;
  float bpm_ = 0.0f;
};

}  // namespace Core

#endif  // CORE_TRACK_H
