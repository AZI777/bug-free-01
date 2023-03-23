#pragma once
#include <iostream>
#include <cstdlib>
#include <ctime>
#define LOC_MAX 512
using namespace std;

class loc // 28 Bytes
{
public:
        loc();
        loc(loc &);
        loc(int, double, double, int, int);
        ~loc();
        void SetNumber(int);
        int GetNumber() const;
        void SetX(double);
        double GetX() const;
        void SetY(double);
        double GetY() const;
        void SetType(int);
        int GetType() const;
        void SetDegree(int);
        int GetDegree() const;
        double RandCoordinate();
        void Print() const;

private:
        int number;
        double x;
        double y;
        int type;
        int degree;
        static int cnt;
};