#include "track.h"

Track::Track() {}

QString Track::title() const {
    return m_title;
}

void Track::setTitle(const QString& title) {
    m_title = title;
}

float Track::bpm() const {
    return m_bpm;
}

void Track::setBpm(float bpm) {
    m_bpm = bpm;
}
