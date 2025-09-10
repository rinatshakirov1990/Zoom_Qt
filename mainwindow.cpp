#include "mainwindow.h"
#include <QGraphicsRectItem>
#include <QGraphicsEllipseItem>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    m_scene = new QGraphicsScene(this);
    m_scene->setSceneRect(-500, -500, 1000, 1000);

    // тестовые примитивы
    m_scene->addRect(-100, -100, 200, 200, QPen(Qt::blue), QBrush(Qt::lightGray));
    m_scene->addEllipse(-200, -200, 100, 100, QPen(Qt::red), QBrush(Qt::yellow));

    m_view = new MyGraphicsView(this);
    m_view->setScene(m_scene);

    setCentralWidget(m_view);
    resize(800, 600);
}
