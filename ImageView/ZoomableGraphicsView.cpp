#include <QWheelEvent>
#include <QDebug>
#include <QWidget>

#include "ZoomableGraphicsView.h"

ZoomableGraphicsView::ZoomableGraphicsView(QWidget *parent)
    : QGraphicsView(parent),
      m_zoomFactor(1.0),
      m_zoomStep(0.1),    // 10% per notch
      m_minZoom(0.1),     // 10% minimum
      m_maxZoom(5.0)      // 500% maximum
{
    setDragMode(QGraphicsView::ScrollHandDrag);
    setRenderHint(QPainter::Antialiasing);
    setRenderHint(QPainter::SmoothPixmapTransform);
}

ZoomableGraphicsView::~ZoomableGraphicsView()
{
    // Destructor can be empty as Qt handles child widgets
}

void ZoomableGraphicsView::wheelEvent(QWheelEvent *event)
{
    if (event->angleDelta().y() > 0)
    {
        // Zoom in
        if (m_zoomFactor < m_maxZoom)
        {
            scale(1 + m_zoomStep, 1 + m_zoomStep);
            m_zoomFactor += m_zoomStep;
        }
    }
    else
    {
        // Zoom out
        if (m_zoomFactor > m_minZoom)
        {
            scale(1 - m_zoomStep, 1 - m_zoomStep);
            m_zoomFactor -= m_zoomStep;
        }
    }

    // Optional: Emit a signal or log the zoom factor
    // qDebug() << "Current Zoom Factor:" << m_zoomFactor;
}


