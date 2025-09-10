#pragma once
#include <QGraphicsView>
#include <QWheelEvent>

class MyGraphicsView : public QGraphicsView
{
    Q_OBJECT
public:
    explicit MyGraphicsView(QWidget *parent = nullptr);

protected:
    void wheelEvent(QWheelEvent *event) override;

private:
    double m_currentScale = 1.0;   // текущий масштаб
    const double m_minScale = 0.05; // минимум (5%)
    const double m_maxScale = 5.0;  // максимум (500%)
};
