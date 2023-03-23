#pragma once
#include <cmath>
#include "loc.h"

class edge
{
public:
        edge();
        edge(edge &);
        edge(loc *, loc *);
        ~edge();
        double Distance() const;
        loc *Origin() const;
        loc *Terminal() const;
        double CalDistance(loc *, loc *);
        void Print() const;

private:
        loc *origin;
        loc *terminal;
        double dist;
};