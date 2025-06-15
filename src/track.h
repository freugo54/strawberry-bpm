#ifndef TRACK_H
#define TRACK_H

#include <QString>

class Track {
public:
    Track();
    QString title() const;
    void setTitle(const QString& title);

    float bpm() const;
    void setBpm(float bpm);

private:
    QString m_title;
    float m_bpm = 0.0f;
};

#endif // TRACK_H
