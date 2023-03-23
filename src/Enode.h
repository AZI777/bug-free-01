#include "edge.h"

class Enode
{
public:
    Enode();
    Enode(Enode &);
    Enode(edge *, Enode *);
    ~Enode();
    edge *Edge;
    Enode *next;
};