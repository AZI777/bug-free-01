#include "NevigationSystem.h"
#include <QPushButton>
#include <QDebug>
NevigationSystem::NevigationSystem(QWidget *parent)
    : QMainWindow(parent), ui(new Ui_NevigationSystem)
{
    ui->setupUi(this);
    resize(2 * LOC_MAX, 2 * LOC_MAX);
    setWindowTitle("Nevigation System");
    // setFixedSize(3*LOC_MAX, 2*LOC_MAX);
    g = new graph();
    g->PrintEdge();
    update();
}

NevigationSystem::~NevigationSystem()
{
    delete ui;
}

void NevigationSystem::paintEvent(QPaintEvent *)
{
    QPainter p(this);
    p.setPen(QPen(Qt::black));
    for (int i = 0; i <= TABLE_SIZE; i++) //每格长宽为32 共8格 9条线
    {
        p.drawLine(QPoint(0, i * (2 * LOC_MAX / TABLE_SIZE)), QPoint(2 * LOC_MAX, i * (2 * LOC_MAX / TABLE_SIZE)));
    }
    for (int i = 0; i <= TABLE_SIZE; i++) //每格长宽为32 共8格 9条线
    {
        p.drawLine(QPoint(i * (2 * LOC_MAX / TABLE_SIZE), 0), QPoint(i * (2 * LOC_MAX / TABLE_SIZE), 2 * LOC_MAX));
    }

    if (g != NULL)
    {
        QPen pen;
        pen.setWidth(5);
        pen.setColor(Qt::red);
        p.setPen(pen);
        for (int i = 0; i < NUM_VERTEX; i++)
        {
            p.drawPoint(QPoint(LOC_MAX + int((g->LocList[i])->GetX()), LOC_MAX + int((g->LocList[i])->GetY())));
        }
        pen.setWidth(2);
        pen.setColor(Qt::darkBlue);
        p.setPen(pen);
        if (g->NumEdge != 0)
        {
            for (int i = 0; i < NUM_VERTEX; i++)
            {
                Lnode *ptr = g->AdjTable[i].head->next;
                for (int j = 0; j < g->AdjTable[i].cnt; j++)
                {
                    p.drawLine(QPoint(LOC_MAX + int(g->AdjTable[i].head->Loc->GetX()), LOC_MAX + int(g->AdjTable[i].head->Loc->GetY())), QPoint(LOC_MAX + (ptr->Loc->GetX()), LOC_MAX + int(ptr->Loc->GetY())));
                }
            }
        }
    }
}