#pragma once
#include <QMainWindow>
#include <QGraphicsScene>
#include "mygraphicsview.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = nullptr);

private:
    QGraphicsScene *m_scene;
    MyGraphicsView *m_view;
};
