#include "Lnode.h"

Lnode::Lnode()
{
    Loc = NULL;
    next = NULL;
}
Lnode::Lnode(Lnode &L)
{
    Loc = new loc(L.Loc->GetNumber(), L.Loc->GetX(),
                  L.Loc->GetY(), L.Loc->GetType(), L.Loc->GetDegree());
    next = NULL;
}
Lnode::Lnode(loc *lo, Lnode *net = NULL)
{
    Loc = lo;
    next = net;
}
Lnode::~Lnode()
{
    
}