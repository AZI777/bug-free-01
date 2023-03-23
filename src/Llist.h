#pragma once
#include "Lnode.h"

class Llist
{
public:
    Llist();
    Llist(Llist &);
    ~Llist();
    void Add(loc *);
    int Count() const;
    void Print() const;
    Lnode *head;
    Lnode *tail;
    int cnt;
};