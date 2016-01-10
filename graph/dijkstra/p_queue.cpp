#include <iostream>
#include <queue>
using namespace std;

struct edge {
  edge(int _to, int _cost) {
    this->to = _to;
    this->cost = _cost;
  }
  int to, cost;
};
typedef pair<int, int> P;

int E, V;
int cost[100][100];
vector<edge> G[1000];
int d[1000];
int INF = 100000;

void dijkstra(int s) {
  priority_queue<P, vector<P>, greater<P> > que;
  fill(d, d + V, INF);
  d[s] = 0;
  que.push(P(0, s));

  while(!que.empty()) {
    P p = que.top(); que.pop();
    int v = p.second;
    if(d[v] < p.first) continue;
    for(int i = 0; i < G[v].size(); i++) {
      edge e = G[v][i];
      if(d[e.to] > d[v] + e.cost) {
        d[e.to] = d[v] + e.cost;
        que.push(P(d[e.to], e.to));
      }
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
    int u, v, c;
    scanf("%d %d %d", &u, &v, &c);
    G[u].push_back(*(new edge(v, c)));
    G[v].push_back(*(new edge(u, c)));
  }
  dijkstra(0);
  for(int i = 0; i < V; i++) {
    printf("%d:%d\n", i, d[i]);
  }
}
