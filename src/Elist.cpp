#include "Elist.h"

Elist::Elist()
{
    head = tail = new Enode();
    cnt = 0;
}

Elist::Elist(Elist &E)
{
    head = new Enode();
    cnt = E.cnt;
    Enode *p1 = E.head;
    Enode *p2 = head;
    for (int i = 0; i < cnt; i++)
    {
        p2->next = new Enode(*(p1->next));
        p1 = p1->next;
        p2 = p2->next;
    }
    tail = p2;
}

Elist::~Elist()
{
    Enode *curr;
    while (head != NULL)
    {
        curr = head;
        head = head->next;
        delete curr;
    }
}

void Elist::Add(edge *Edge)
{
    tail = tail->next = new Enode(Edge, NULL);
    cnt++;
}

int Elist::Count() const
{
    return cnt;
}

void Elist::Print() const
{
    Enode *curr = head;
    while (curr->next != NULL) //注意：保证head不为空指针
    {
        curr = curr->next;
        curr->Edge->Print();
    }
}