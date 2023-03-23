#include <iostream>
#include <QDebug>
#include <QApplication>
#include "NevigationSystem.h"
//#pragma comment(lib, "user32.lib")
using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    NevigationSystem w;
    w.show();
    return a.exec();
}
