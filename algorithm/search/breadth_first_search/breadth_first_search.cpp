#include <cstdio>
#include <iostream>
#include <queue>

typedef std::pair<int, int> P;

const int INF = 10000000;
const int MAX_N = 15, MAX_M = 15;

char maze[MAX_N][MAX_M];
int d[MAX_N][MAX_M];
int n, m;
int sx, sy;
int gx, gy;
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

int bfs() {
  std::queue<P> queue;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      d[i][j] = INF;
    }
  }

  queue.push(P(sx, sy));
  d[sx][sy] = 0;

  while(queue.size()) {
    P p = queue.front(); queue.pop();
    if(p.first == gx && p.second == gy) break;
    for(int i = 0; i < 4; i++) {
      int nx = p.first + dx[i], ny = p.second + dy[i];
      if(0 <= nx && nx < n && 0 <= ny && ny < m && maze[nx][ny] != '#' && d[nx][ny] == INF) {
        queue.push(P(nx, ny));
        d[nx][ny] = d[p.first][p.second] + 1;
      }
    }
  }
  return d[gx][gy];
}

int solve() {
  return bfs();
}

void read_input() {
  scanf("%d %d\n", &n, &m);
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      scanf("%c", &maze[i][j]);
      if(maze[i][j] == 'S') {
        sx = i;
        sy = j;
      }
      if(maze[i][j] == 'G') {
        gx = i;
        gy = j;
      }
    }
    scanf("\n");
  }
}

int main() {
  read_input();
  printf("%d\n", solve());
  return 0;
}
