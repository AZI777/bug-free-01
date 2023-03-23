#include "loc.h"

class Lnode
{
public:
    Lnode();
    Lnode(Lnode &);
    Lnode(loc *, Lnode *);
    ~Lnode();
    loc *Loc;
    Lnode *next;
};