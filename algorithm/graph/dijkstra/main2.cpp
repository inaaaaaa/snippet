#include <iostream>
#include <queue>

using namespace std;

const int INF = 10000;
const int MAX_NODE = 3000;
const int MAX_EDGE = 4500000;

int T; // test case
int N; // nodes
int M; // edges

int COST[MAX_NODE][MAX_NODE];
int DISTANCE[MAX_NODE];

// dijkstra
void ans(int start) {
  // top is min distance
  // pair<int, int> -> pair<distance, node>
  priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
  DISTANCE[start] = 0;
  pq.push(pair<int, int>(DISTANCE[start], start));

  while (!pq.empty()) {
    pair<int, int> x = pq.top();
    pq.pop();
    int _distance = x.first;
    int _node = x.second;
    if (DISTANCE[_node] < _distance) continue;

    for (int i = 0; i < N; i++) {
      if (DISTANCE[i] > DISTANCE[_node] + COST[_node][i]) {
        DISTANCE[i] = DISTANCE[_node] + COST[_node][i];
        pq.push(pair<int, int>(DISTANCE[i], i));
      }
    }
  }
}

void init() {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (i == j) {
        COST[i][j] = 0;
      } else {
        COST[i][j] = INF;
      }
    }
  }
  for (int i = 0; i < N; i++) {
    DISTANCE[i] = INF;
  }
}

int main() {
  cin >> T;
  for (int t = 0; t < T; t++) {
    cin >> N >> M;
    init();
    for (int i = 0; i < M; i++) {
      int from, to, _cost;
      cin >> from >> to >> _cost;
      from--;
      to--;
      if (COST[from][to] > _cost) {
        COST[from][to] = _cost;
        COST[to][from] = _cost;
      }
    }
    int S;
    cin >> S;
    S--;
    ans(S);
    for (int i = 0; i < N; i++) {
      if (DISTANCE[i] == 0) continue;
      if (DISTANCE[i] == INF) {
        cout << -1 << " ";
      } else {
        cout << DISTANCE[i] << " ";
      }
    }
    cout << endl;
  }
}
