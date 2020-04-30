#ifndef AUDIO_H
#define AUDIO_H

#include <QObject>
#include <QAudioFormat>
#include <QAudioDeviceInfo>
#include <QAudioInput>
#include <QFile>

class Audio : public QObject
{
    Q_OBJECT
public:
    explicit Audio(QObject *parent = nullptr);

    void startAudio(const QString &fileName);
    void stopAudio();

signals:

public slots:

private:
    QAudioInput * m_audio;
    QFile *m_file;
};

#endif // AUDIO_H
