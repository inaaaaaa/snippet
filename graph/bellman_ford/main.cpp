#include <iostream>

struct edge { int from, to, cost; };

edge es[100];
int d[100];
int INF = 100000;
int V, E;

// obtain shortest path
void bellman_ford(int s) {
  for(int i = 0; i < V; i++) d[i] = INF;
  d[s] = 0;
  while(true) {
    bool update = false;
    for(int i = 0; i < E; i++) {
      edge e = es[i];
      if(d[e.from] != INF && d[e.to] > d[e.from] + e.cost) {
        d[e.to] = d[e.from] + e.cost;
        update = true;
      }
    }
    if(!update) break;
  }
}

int main() {
  scanf("%d %d", &V, &E);
  for(int i = 0; i < E; i++) {
    scanf("%d %d %d", &es[i].from, &es[i].to, &es[i].cost);
  }
  bellman_ford(0);
  for(int i = 0; i < V; i++) {
    printf("%d:%d\n", i, d[i]);
  }
}
