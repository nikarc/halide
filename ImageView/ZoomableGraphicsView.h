// ZoomableGraphicsView.h

#ifndef ZOOMABLEGRAPHICSVIEW_H
#define ZOOMABLEGRAPHICSVIEW_H

#include <QGraphicsView>
#include <QWheelEvent>

class ZoomableGraphicsView : public QGraphicsView
{
    Q_OBJECT

public:
    explicit ZoomableGraphicsView(QWidget *parent = nullptr);
    ~ZoomableGraphicsView();

protected:
    void wheelEvent(QWheelEvent *event) override;

private:
    double m_zoomFactor;          // Current zoom factor
    const double m_zoomStep;      // Zoom step per wheel notch
    const double m_minZoom;       // Minimum zoom level
    const double m_maxZoom;       // Maximum zoom level
};

#endif // ZOOMABLEGRAPHICSVIEW_H


