#include "loc.h"

int loc::cnt = 0;

double loc::RandCoordinate()
{

    double ret = -LOC_MAX + (double(rand() % (LOC_MAX * 20))) / (double(10));
    // ret范围：[-1024,1024) 目前是-128~128
    return ret;
}

void loc::Print() const
{
    cout << "number:" << number << " x:" << x << " y:" << y << " type:" << type << " degree:" << degree << endl;
}

loc::loc()
{
    number = cnt++;
    x = RandCoordinate();
    y = RandCoordinate();
    type = 0;
    degree = 0;
}

loc::loc(loc &L)
{
    number = L.number;
    x = L.x;
    y = L.y;
    type = L.type;
    degree = L.degree;
}

loc::loc(int num, double InputX, double InputY, int Tp, int Deg)
{
    number = num;
    x = InputX;
    y = InputY;
    type = Tp;
    degree = Deg;
}

loc::~loc()
{
    cout << "[TEST]LOCATION DESTRUCTED." << endl;
}

void loc::SetNumber(int num)
{
    number = num;
}

int loc::GetNumber() const
{
    return number;
}

void loc::SetX(double InputX)
{
    x = InputX;
}

double loc::GetX() const
{
    return x;
}

void loc::SetY(double InputY)
{
    y = InputY;
}

double loc::GetY() const
{
    return y;
}

void loc::SetType(int InputType)
{
    type = InputType;
}

int loc::GetType() const
{
    return type;
}

void loc::SetDegree(int InputDegree)
{
    degree = InputDegree;
}

int loc::GetDegree() const
{
    return degree;
}