#include <iostream>
using namespace std;

struct edge { int from, to, cost; };

edge es[100];
int d[100];
int INF = 100000;
int V, E;

void shortest_path(int s) {
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
  shortest_path(0);
  for(int i = 0; i < V; i++) {
    cout << i << ":" << d[i] << endl;
  }
}
