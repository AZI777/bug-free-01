#include <iostream>
#include "Llist.h"

Llist::Llist()
{
    head = tail = new Lnode();
    cnt = 0;
}

Llist::Llist(Llist &L)
{
    head = new Lnode();
    cnt = L.cnt;
    Lnode *p1 = L.head;
    Lnode *p2 = head;
    for (int i = 0; i < cnt; i++)
    {
        p2->next = new Lnode(*(p1->next));
        p1 = p1->next;
        p2 = p2->next;
    }
    tail = p2;
}

Llist::~Llist()
{
    Lnode *curr;
    while (head != NULL)
    {
        curr = head;
        head = head->next;
        delete curr;
    }
}

void Llist::Add(loc *Loc)
{
    if (tail == NULL)
        cout << "tail is NULL" << endl;
    else
    {
        tail = tail->next = new Lnode(Loc, NULL);
        cnt++;
    }
}

int Llist::Count() const
{
    return cnt;
}

void Llist::Print() const
{
    Lnode *curr = head;
    while (curr->next != NULL) //注意：保证head不为空指针
    {
        curr = curr->next;
        curr->Loc->Print();
    }
    cout << endl;
}