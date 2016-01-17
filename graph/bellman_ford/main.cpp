#include <iostream>

struct Edge {
  Edge() {}
  ~Edge() {}
  Edge(int from, int to, int cost) {
    this->from = from;
    this->to = to;
    this->cost = cost;
  }
  int from, to, cost;
};

const int MAX_V = 100;
const int MAX_E = 100;
const int INF = 100000;
int V, E;
int DISTANCE[MAX_V];
Edge EDGES[MAX_E];

void bellman_ford(int start) {
  // initialize
  std::fill(DISTANCE, DISTANCE + V, INF);
  DISTANCE[start] = 0;

  while(true) {
    bool update = false;
    for(int i = 0; i < 2 * E; i++) {
      Edge e = EDGES[i];
      if(DISTANCE[e.from] != INF && DISTANCE[e.to] > DISTANCE[e.from] + e.cost) {
        DISTANCE[e.to] = DISTANCE[e.from] + e.cost;
        update = true;
      }
    }
    if(!update) break;
  }
}

int main() {
  scanf("%d %d", &V, &E);
  for(int i = 0; i < E; i++) {
    int from, to, cost;
    scanf("%d %d %d", &from, &to, &cost);
    // undirected graph
    EDGES[2 * i] = Edge(from, to, cost);
    EDGES[2 * i + 1] = Edge(to, from, cost);
  }
  bellman_ford(0);
  for(int i = 0; i < V; i++) {
    printf("vertex:%d, distance:%d\n", i, DISTANCE[i]);
  }
}
