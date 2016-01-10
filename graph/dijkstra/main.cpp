#include <iostream>
using namespace std;

int cost[100][100];
int d[100];
bool used[100];
int E;
int V;
int INF = 100000;

void dijkstra(int s) {
  fill(d, d + V, INF);
  fill(used, used + V, false);
  d[s] = 0;
  while(true) {
    int v = -1;
    for(int u = 0; u < V; u++) {
      if(!used[u] && (v == -1 || d[u] < d[v])) v = u;
    }
    if(v == -1) break;
    used[v] = true;
    for(int u = 0; u < V; u++) {
      d[u] = min(d[u], d[v] + cost[v][u]);
    }
  }
}

int main() {
  scanf("%d %d", &E, &V);
  for(int i = 0; i < V; i++) {
    for(int j = 0; j < V; j++) {
      cost[i][j] = INF;
    }
  }
  for(int i = 0; i < E; i++) {
    int u, v, _cost;
    scanf("%d %d %d", &u, &v, &_cost);
    cost[u][v] = _cost;
    cost[v][u] = _cost;
  }
  dijkstra(0);
  for(int i = 0; i < V; i++) {
    printf("%d:%d\n", i, d[i]);
  }
}
