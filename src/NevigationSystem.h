#pragma once
#include "ui_NevigationSystem.h"
#include "graph.h"
#include <QMainWindow>
#include <QPainter>
class NevigationSystem : public QMainWindow
{
    Q_OBJECT //允许使用信号和槽机制

public : 
    NevigationSystem(QWidget *parent = nullptr);
    ~NevigationSystem();
    void paintEvent(QPaintEvent*);
private:
    Ui_NevigationSystem *ui;
    graph* g;
};