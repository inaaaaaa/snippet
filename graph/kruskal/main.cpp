#include <iostream>

struct Edge
{
  Edge() {}
  ~Edge() {}
  Edge(int u, int v, int cost) {
    this->u = u;
    this->v = v;
    this->cost = cost;
  }
  int u, v, cost;
};

bool comp(const Edge& e0, const Edge& e1) {
  return e0.cost < e1.cost;
}

const int MAX_E = 100;
const int MAX_V = 100;
Edge es[MAX_E];
int V, E;
int par[MAX_V];
int rank[MAX_V];

void init_union_find(int n) {
  for(int i = 0; i < n; i++) {
    par[i] = i;
    rank[i] = 0;
  }
}

int find(int x) {
  if(par[x] == x) {
    return x;
  } else {
    return par[x] = find(par[x]);
  }
}

void unite(int x, int y) {
  x = find(x);
  y = find(y);
  if(x == y) return;
  if(rank[x] < rank[y]) {
    par[x] = y;
  } else {
    par[y] = x;
    if (rank[x] == rank[y]) rank[x]++;
  }
}

bool same(int x, int y) {
  return find(x) == find(y);
}

int kruskal() {
  std::sort(es, es + E, comp); // ascending order
  init_union_find(V);
  int res = 0;
  for(int i = 0; i < E; i++) {
    Edge e = es[i];
    if(!same(e.u, e.v)) {
      unite(e.u, e.v);
      res += e.cost;
    }
  }
  return res;
}

int main() {
  scanf("%d %d", &V, &E);
  for(int i = 0; i < E; i++) {
    int from, to, cost;
    scanf("%d %d %d", &from, &to, &cost);
    es[i] = *(new Edge(from, to, cost));
  }
  int res = kruskal();
  printf("%d\n", res);
}
