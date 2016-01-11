#include <iostream>
using namespace std;

/**
 * The Bellman-Ford algorithm
 * shortest path
 * O(|V| * |E|)
 */

struct edge {
  edge() {}
  edge(int from, int to, int cost) {
    this->from = from;
    this->to = to;
    this->cost = cost;
  }
  int from, to, cost;
};

edge es[100];
int d[100];
int INF = 100000;
int V, E;

int log_i = 0;
void log() {
  printf("==== log : %d ====\n", log_i++);
  for(int i = 0; i < V; i++) {
    printf("node:%d cost:%d\n", i, d[i]);
  }
}

void bellman_ford(int s) {
  // initialize
  std::fill(d, d + V, INF);
  d[s] = 0;

  // O(|V|)
  while(true) {
    bool update = false;
    // O(|E|)
    for(int i = 0; i < 2 * E; i++) {
      edge e = es[i];
      if(d[e.from] != INF && d[e.to] > d[e.from] + e.cost) {
        d[e.to] = d[e.from] + e.cost;
        update = true;
      }
      log();
    }
    if(!update) break;
  }
}

int main() {
  scanf("%d %d", &V, &E);
  for(int i = 0; i < E; i++) {
    int from, to, cost;
    scanf("%d %d %d", &from, &to, &cost);
    // Undirected graph
    es[2 * i] = edge(from, to, cost);
    es[2 * i + 1] = edge(to, from, cost);
  }

  bellman_ford(0);

  printf("==== answer ====\n");
  for(int i = 0; i < V; i++) {
    printf("node:%d cost:%d\n", i, d[i]);
  }
}
