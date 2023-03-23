#include "edge.h"
using namespace std;

double edge::CalDistance(loc *p1, loc *p2)
{
    if (p1 != NULL && p2 != NULL)
        return sqrt(pow((p1->GetX() - p2->GetX()), 2) + pow((p1->GetY() - p2->GetY()), 2));
    else
    {
        if (p1 == NULL)
            cout << "[ERROR]p1 is nullptr." << endl;
        if (p2 == NULL)
            cout << "[ERROR]p2 is nullptr." << endl;
        return 0;
    }
}

edge::edge()
{
    origin = terminal = NULL;
    dist = 0;
}

edge::edge(edge &E)
{
    if (E.origin != nullptr && E.terminal != nullptr)
    {
        origin = E.origin;
        terminal = E.terminal;
        dist = E.dist;
    }
    else
    {
        cout << "[1]Edge is constructed fail." << endl;
    }
}

edge::edge(loc *start, loc *end)
{
    if (start != nullptr && end != nullptr)
    {
        origin = start;
        terminal = end;
        dist = CalDistance(start, end);
    }
    else
    {
        cout << "[2]Edge is constructed fail." << endl;
    }
}

edge::~edge()
{
}

double edge::Distance() const
{
    return dist;
}

loc *edge::Origin() const
{
    return origin;
}

loc *edge::Terminal() const
{
    return terminal;
}

void edge::Print() const
{
    cout << "origin:" << origin->GetNumber() << " terminal:" << terminal->GetNumber() << " distance:" << dist << endl;
}