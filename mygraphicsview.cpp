#include "mygraphicsview.h"

MyGraphicsView::MyGraphicsView(QWidget *parent)
    : QGraphicsView(parent)
{
    setRenderHint(QPainter::Antialiasing);
    setDragMode(QGraphicsView::NoDrag);

    // Масштабирование относительно курсора
    setTransformationAnchor(QGraphicsView::AnchorUnderMouse);
    setResizeAnchor(QGraphicsView::AnchorViewCenter);

    setViewportUpdateMode(QGraphicsView::SmartViewportUpdate);
}

void MyGraphicsView::wheelEvent(QWheelEvent *event)
{
    // Чувствительность масштабирования
    const double zoomStep = 1.15;

    if (event->angleDelta().y() > 0) {
        m_currentScale *= zoomStep;
    } else {
        m_currentScale /= zoomStep;
    }

    // Ограничение масштаба
    if (m_currentScale < m_minScale) m_currentScale = m_minScale;
    if (m_currentScale > m_maxScale) m_currentScale = m_maxScale;

    // Сбрасываем трансформацию и устанавливаем новый масштаб
    QTransform t;
    t.scale(m_currentScale, m_currentScale);
    setTransform(t);
}
