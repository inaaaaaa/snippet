#include <iostream>

const int MAX_V = 100;
const int INF = 10000;
int cost[MAX_V][MAX_V];
int mincost[MAX_V];
bool used[MAX_V];
int V, E;

int prim() {
  for(int i = 0; i < V; i++) {
    mincost[i] = INF;
    used[i] = false;
  }
  mincost[0] = 0;
  int res = 0;
  while(true) {
    int v = -1;
    for(int u = 0; u < V; u++) {
      if(!used[u] && (v == -1 || mincost[u] < mincost[v])) {
        v = u;
      }
    }
    if(v == -1) break;
    used[v] = true;
    res += mincost[v];
    for(int u = 0; u < V; u++) {
      mincost[u] = std::min(mincost[u], cost[v][u]);
    }
  }
  return res;
}

int main() {
  scanf("%d %d", &V, &E);
  for(int i = 0; i < V; i++) {
    for(int j = 0; j < V; j++) {
      if(i == j) {
        cost[i][j] = 0;
      } else {
        cost[i][j] = INF;
      }
    }
  }
  for(int i = 0; i < E; i++) {
    int from, to, c;
    scanf("%d %d %d", &from, &to, &c);
    cost[from][to] = c;
    cost[to][from] = c;
  }
  int res = prim();
  printf("%d\n", res);
}
