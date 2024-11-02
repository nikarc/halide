#ifndef CAMERARAWIMAGE_H
#define CAMERARAWIMAGE_H

#include <QObject>
#include <QImage>
#include <libraw/libraw.h>

class CameraRawImage : public QObject
{
public:
    CameraRawImage();

private:
    LibRaw rawProcessor;

public slots:
    QImage convertRawToQImage(const char* filePath);
};

#endif // CAMERARAWIMAGE_H
