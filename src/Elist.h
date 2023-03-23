#include "Enode.h"

class Elist
{
public:
    Elist();
    Elist(Elist &);
    ~Elist();
    void Add(edge *);
    int Count() const;
    void Print() const;

private:
    Enode *head;
    Enode *tail;
    int cnt;
};