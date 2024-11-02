#ifndef HALIDE_H
#define HALIDE_H

#include <QMainWindow>
#include <QGraphicsScene>
#include "ImageView/ZoomableGraphicsView.h"
#include "cameraRawImage.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class Halide;
}
QT_END_NAMESPACE

class Halide : public QMainWindow
{
    Q_OBJECT

public:
    Halide(QWidget *parent = nullptr);
    ~Halide();

private slots:
    void on_actionOpen_triggered();

private:
    Ui::Halide *ui;
    CameraRawImage* m_cameraRawImage;
    ZoomableGraphicsView* m_graphicsView;
    QGraphicsScene* m_graphicsScene;
};
#endif // HALIDE_H
