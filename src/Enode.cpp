#include "Enode.h"

Enode::Enode()
{
    Edge = NULL;
    next = NULL;
}
Enode::Enode(Enode &E)
{
    Edge = new edge(E.Edge->Origin(), E.Edge->Terminal());
    next = NULL;
}
Enode::Enode(edge *e, Enode *net = NULL)
{
    Edge = e;
    next = net;
}
Enode::~Enode()
{
}