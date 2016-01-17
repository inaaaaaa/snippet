#include <iostream>
#include <queue>
#include <vector>

struct Edge {
  Edge() {}
  ~Edge() {}
  Edge(int to, int cost) {
    this->to = to;
    this->cost = cost;
  }
  int to;
  int cost;
};

// first is a distance, second is a vertex's number.
typedef std::pair<int, int> P;

const int MAX_V = 1000;
const int INF = 100000;
int E, V; // number of edge, vertex
std::vector<Edge> GRAPH[MAX_V]; // is an array of vector<Edge>.
int DISTANCE[MAX_V];
int PRIV[MAX_V];

void dijkstra(int start) {
  // initialize
  std::priority_queue<P, std::vector<P>, std::greater<P> > min_pq;
  std::fill(DISTANCE, DISTANCE + V, INF);
  DISTANCE[start] = 0;
  min_pq.push(P(0, start));

  while(!min_pq.empty()) {
    P p = min_pq.top(); // top is the P of min distance.
    min_pq.pop();
    int v = p.second;
    if(DISTANCE[v] < p.first) continue;

    // loop neighboring vertexes
    for(int i = 0; i < GRAPH[v].size(); i++) {
      Edge e = GRAPH[v][i];
      if(DISTANCE[e.to] > DISTANCE[v] + e.cost) {
        DISTANCE[e.to] = DISTANCE[v] + e.cost;
        min_pq.push(P(DISTANCE[e.to], e.to));
        PRIV[e.to] = v;
      }
    }
  }
}

std::vector<int> get_path(int start, int goal) {
  std::vector<int> path;
  int v = goal;
  while(true) {
    path.push_back(v);
    if(v == start) break;
    v = PRIV[v];
  }
  reverse(path.begin(), path.end());
  return path;
}

int main() {
  scanf("%d %d", &V, &E);
  for(int i = 0; i < E; i++) {
    int u, v, c;
    scanf("%d %d %d", &u, &v, &c);
    // undirected graph
    GRAPH[u].push_back(*(new Edge(v, c)));
    GRAPH[v].push_back(*(new Edge(u, c)));
  }
  int start = 0;
  dijkstra(start);
  std::vector<int> path = get_path(start, 6);
  for(int i = 0; i < path.size(); i++) {
    printf("%d ", path[i]);
  }
  printf("\n");
}
