#include "core/track.h"

namespace Core {

Track::Track() = default;
Track::~Track() = default;

QString Track::Title() const {
  return title_;
}

void Track::SetTitle(const QString &title) {
  title_ = title;
}

// NEU: BPM
float Track::Bpm() const {
  return bpm_;
}

void Track::SetBpm(float bpm) {
  bpm_ = bpm;
}

bool Track::operator==(const Track &other) const {
  return title_ == other.title_ &&
         bpm_ == other.bpm_;
  // ggf. weitere Felder ergänzen
}

}  // namespace Core
