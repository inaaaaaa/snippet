#include <iostream>

const int INF = 10000;
const int MAX_V = 100;
int DISTANCE[MAX_V][MAX_V];
int V, E;

void warshall_floyd() {
  for(int k = 0; k < V; k++) {
    for(int i = 0; i < V; i++) {
      for(int j = 0; j < V; j++) {
        DISTANCE[i][j] = std::min(DISTANCE[i][j], DISTANCE[i][k] + DISTANCE[k][j]);
      }
    }
  }
}

int main() {
  // initialize
  scanf("%d %d", &V, &E);
  for(int i = 0; i < V; i++) {
    for(int j = 0; j < V; j++) {
      if(i == j) {
        DISTANCE[i][j] = 0;
      } else {
        DISTANCE[i][j] = INF;
      }
    }
  }
  for(int i = 0; i < E; i++) {
    int from, to, cost;
    scanf("%d %d %d", &from, &to, &cost);
    DISTANCE[from][to] = cost;
    DISTANCE[to][from] = cost;
  }

  warshall_floyd();

  for(int i = 0; i < V; i++) {
    printf("from:%d\n", i);
    for(int j = 0; j < V; j++) {
      printf("  to:%d, distance:%d\n", j, DISTANCE[i][j]);
    }
  }
}
