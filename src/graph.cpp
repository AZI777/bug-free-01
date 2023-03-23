#include <iostream>
#include "graph.h"

using namespace std;

graph::graph()
{
    srand(SEED);
    NumLoc = 0;
    NumEdge = 0;
    AdjTable = new Llist[NUM_VERTEX];
    GeoTable = new Llist *[TABLE_SIZE];
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        GeoTable[i] = new Llist[TABLE_SIZE];
    }
    Init();
}

void graph::InitLoc()
{
    for (int i = 0; i < NUM_VERTEX; i++)
        AddLoc();
}

void graph::InitEdge()
{
    // Use bfs method to construct edge for the graph.
    queue<loc *> q;
    loc *curr;
    q.push(FindLoc(0));
    isVisited[0] = true;
    while (!q.empty())
    {
        curr = q.front();
        q.pop();
        vector<loc *> v =Neighbor(curr); // A set of curr's neighbor.
        if (v.size() != 0)
        {
            random_shuffle(v.begin(), v.end());
            int Add = getRand(1, v.size());
            // int Add = v->size();
            for (int i = 0; i < Add; i++)
            {
                q.push(v[i]);
                AddEdge(curr, v[i]);
                isVisited[v[i]->GetNumber()] = true;
            }
        }
        else
        {
            continue;
        }
    }
}

void graph::Init()
{
    InitLoc();
    InitEdge();
}

graph::~graph()
{
}

inline void graph::HashLoc(loc *Loc)
{
    GeoTable[HashX(Loc)][HashY(Loc)].Add(Loc);
}

void graph::AddLoc()
{
    loc *temp = new loc();
    isVisited[NumLoc] = false;
    AdjTable[NumLoc].head->Loc = temp;
    LocList[NumLoc] = temp;
    HashLoc(temp);
    NumLoc++;
}

void graph::AddEdge(loc *l1, loc *l2)
{
    AdjTable[l1->GetNumber()].Add(l2);
    AdjTable[l2->GetNumber()].Add(l1);
    NumEdge++;
}

void graph::PrintLoc() const
{
    for (int i = 0; i < NumLoc; i++)
    {
        LocList[i]->Print();
    }
}

void graph::PrintEdge() const
{
    for (int i = 0; i < NUM_VERTEX; i++)
    {
        if (AdjTable[i].Count() != 0)
        {
            cout << AdjTable[i].head->Loc->GetNumber() << "---->";
            Lnode *p = AdjTable[i].head;
            for (int j = 0; j < AdjTable[i].Count() - 1; j++)
            {
                p = p->next;
                cout << p->Loc->GetNumber() << ",";
            }
            p = p->next;
            cout << p->Loc->GetNumber() << endl;
        }
        else
        {
            cout << i << " with no edge." << endl;
            continue;
        }
    }
    cout<<"NumEdge:"<<NumEdge<<endl;
}

void graph::PrintByTable() const
{
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        for (int j = 0; j < TABLE_SIZE; j++)
        {
            if (GeoTable[i][j].Count() != 0)
            {
                cout << "GeoTable[" << i << "][" << j << "]:" << endl;
                GeoTable[i][j].Print();
            }
        }
    }
}

int graph::HashX(loc *Loc)
{
    return (int(Loc->GetX()) + LOC_MAX) / (2 * LOC_MAX / TABLE_SIZE);
}

int graph::HashY(loc *Loc)
{
    return (int(Loc->GetY()) + LOC_MAX) / (2 * LOC_MAX / TABLE_SIZE);
}

Llist *graph::NeighborHelp(loc *Loc, int r)
{
    int x = HashX(Loc);
    int y = HashY(Loc);
    if (r == 0)
    {
        Llist *res = new Llist();
        Lnode *p = GeoTable[x][y].head;
        while (p != nullptr)
        {
            if (p->next != nullptr)
            {
                if ((p->next->Loc != Loc) && (!(isVisited[(p->next->Loc)->GetNumber()])) && (CanEdge(Loc, p->next->Loc)))
                {
                    res->Add(p->next->Loc);
                }
                p = p->next;
            }
            else
                break;
        }
        return res;
    }
    else //注意坐标范围//需要改内存泄漏
    {
        Llist *res = new Llist();

        for (int i = x - r, j = y - r; j <= y + r; j++) //左列
        {
            if (0 <= i && i < TABLE_SIZE && 0 <= j && j < TABLE_SIZE)
            {
                Llist *temp = new Llist();
                Llist *temp2 = res;
                Lnode *p = GeoTable[i][j].head;
                while (p != nullptr)
                {
                    if (p->next != nullptr)
                    {
                        if (isVisited[(p->next->Loc)->GetNumber()] == false && CanEdge(Loc, p->next->Loc))
                        {
                            temp->Add(p->next->Loc);
                        }
                        p = p->next;
                    }
                    else
                        break;
                }
                res = link(*temp2, *temp);
                delete temp;
                delete temp2;
            }
        }

        for (int i = x + r, j = y - r; j <= y + r; j++) //右列
        {
            if (0 <= i && i < TABLE_SIZE && 0 <= j && j < TABLE_SIZE)
            {
                Llist *temp = new Llist();
                Llist *temp2 = res;
                Lnode *p = GeoTable[i][j].head;
                while (p != nullptr)
                {
                    if (p->next != nullptr)
                    {
                        if (isVisited[(p->next->Loc)->GetNumber()] == false && CanEdge(Loc, p->next->Loc))
                        {
                            temp->Add(p->next->Loc);
                        }
                        p = p->next;
                    }
                    else
                        break;
                }
                res = link(*temp2, *temp);
                delete temp;
                delete temp2;
            }
        }

        for (int i = x - r + 1, j = y - r; i <= x + r - 1; i++) //上列
        {
            if (0 <= i && i < TABLE_SIZE && 0 <= j && j < TABLE_SIZE)
            {
                Llist *temp = new Llist();
                Llist *temp2 = res;
                Lnode *p = GeoTable[i][j].head;
                while (p != nullptr)
                {
                    if (p->next != nullptr)
                    {
                        if (isVisited[(p->next->Loc)->GetNumber()] == false && CanEdge(Loc, p->next->Loc))
                        {
                            temp->Add(p->next->Loc);
                        }
                        p = p->next;
                    }
                    else
                        break;
                }
                res = link(*temp2, *temp);
                delete temp;
                delete temp2;
            }
        }

        for (int i = x - r + 1, j = y + r; i <= x + r - 1; i++) //下列
        {
            if (0 <= i && i < TABLE_SIZE && 0 <= j && j < TABLE_SIZE)
            {
                Llist *temp = new Llist();
                Llist *temp2 = res;
                Lnode *p = GeoTable[i][j].head;
                while (p != nullptr)
                {
                    if (p->next != nullptr)
                    {
                        if (isVisited[(p->next->Loc)->GetNumber()] == false && CanEdge(Loc, p->next->Loc))
                        {
                            temp->Add(p->next->Loc);
                        }
                        p = p->next;
                    }
                    else
                        break;
                }
                res = link(*temp2, *temp);
                delete temp;
                delete temp2;
            }
        }

        return res;
    }
}

vector<loc *> graph::Neighbor(loc *Loc) //修改内存泄漏
{
    Llist *temp = NeighborHelp(Loc, 0);
    int r = 1;
    while (temp->Count() == 0 && r < TABLE_SIZE)
    {
        delete temp;
        temp = NeighborHelp(Loc, r);
        r++;
    }
    vector<loc *> res(temp->Count());
    Lnode *curr = temp->head;
    for (int i = 0; i < temp->Count(); i++, curr = curr->next)
        res[i] = (curr->next->Loc);
    delete temp;
    return res;
}

loc *graph::FindLoc(int num)
{
    if (0 <= num && num < NUM_VERTEX)
    {
        return LocList[num];
    }
    else
    {
        cout << "Wrong number." << endl;
        return NULL;
    }
}

Llist *graph::link(Llist &L1, Llist &L2)
{
    if (L1.Count() != 0 && L2.Count() != 0)
    {
        Llist *res = new Llist();
        Lnode *p = L1.head;
        for (int i = 0; i < L1.Count(); i++)
        {
            res->Add(p->next->Loc);
            p = p->next;
        }
        p = L2.head;
        for (int i = 0; i < L2.Count(); i++)
        {
            res->Add(p->next->Loc);
            p = p->next;
        }
        return res;
    }
    if (L1.Count() == 0)
    {
        return new Llist(L2);
    }
    return new Llist(L1);
}

bool graph::isIntersect(edge *E1, edge *E2) //非端点处相交
{

    double x1 = E1->Origin()->GetX();
    double y1 = E1->Origin()->GetY();
    double x2 = E1->Terminal()->GetX();
    double y2 = E1->Terminal()->GetY();
    double x3 = E2->Origin()->GetX();
    double y3 = E2->Origin()->GetY();
    double x4 = E2->Terminal()->GetX();
    double y4 = E2->Terminal()->GetY();
    if (max(x1, x2) < min(x3, x4) || max(x3, x4) < min(x1, x2) || max(y1, y2) < min(y3, y4) || max(y3, y4) < min(y1, y2))
    {
        return false;
    }
    return (((((x1 - x3) * (y4 - y3)) - ((x4 - x3) * (y1 - y3))) * (((x2 - x3) * (y4 - y3)) - ((x4 - x3) * (y2 - y3)))) < 0);
}

int graph::getRand(int min, int max)
{
    if (min == max)
        return min;
    return min + rand() % (max - min + 1);
}

bool graph::CanEdge(loc *L1, loc *L2)
{
    // Search all edges.
    edge *E1 = new edge(L1, L2);
    for (int i = 0; i < NUM_VERTEX; i++)
    {
        Lnode *p = AdjTable[i].head;
        int t = AdjTable[i].cnt;
        for (int j = 0; j < AdjTable[i].cnt; j++)
        {
            p = p->next;
            edge *E2 = new edge(AdjTable[i].head->Loc, p->Loc);
            if (isIntersect(E1, E2) == true)
            {
                //cout << "E1:(" << E1->Origin()->GetNumber() << "," << E1->Terminal()->GetNumber() << ") x E2:(" << E2->Origin()->GetNumber() << "," << E2->Terminal()->GetNumber() << ")" << endl;
                return false;
            }
        }
    }
    return true;
}

void graph::PrintVector(vector<loc *> v)
{
    for (int i = 0; i < v.size() - 1; i++)
    {
        cout << v[i]->GetNumber() << ",";
    }
    cout << v[v.size() - 1]->GetNumber() << endl;
}
