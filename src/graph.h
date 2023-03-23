#include "Elist.h"
#include "Llist.h"
#include <vector>
#include <queue>
#include <algorithm>
#include <QDebug>
#include <cmath>
#define NUM_VERTEX 2000
#define TABLE_SIZE 32
#define SEED 0
class graph
{
public:
   graph();
   ~graph();
   void InitLoc();
   void AddLoc();
   void InitEdge();
   void AddEdge(loc *, loc *);
   void PrintLoc() const;
   void PrintEdge() const;
   void PrintByTable() const;
   inline void HashLoc(loc *);
   void Init();
   inline int HashX(loc *);
   inline int HashY(loc *);
   loc *FindLoc(int);
   Llist *NeighborHelp(loc *, int);
   vector<loc *> Neighbor(loc *);
   void PrintVector(vector<loc *>);
   Llist *link(Llist &, Llist &);
   bool isIntersect(edge *, edge *);
   bool CanEdge(loc *, loc *);
   int getRand(int, int);

   // variable
   loc *LocList[NUM_VERTEX];
   bool isVisited[NUM_VERTEX];
   int NumLoc;
   Llist **GeoTable;
   Llist *AdjTable; // Adjacency table
   // Elist EdgeList;
   int NumEdge;
};