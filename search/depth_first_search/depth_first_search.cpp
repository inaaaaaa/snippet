#include <cstdio>

int n, m;
char field[15][15];

void dfs(int x, int y) {
  field[x][y] = '.';
  for(int dx = -1; dx <= 1; dx++) {
    for(int dy = -1; dy <= 1; dy++) {
      int nx = x + dx;
      int ny = y + dy;
      if(0 <= nx && nx < n && 0 <= ny && ny < m && field[nx][ny] == 'W') {
        dfs(nx, ny);
      }
    }
  }
}

int solve() {
  int res = 0;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      if(field[i][j] == 'W') {
        dfs(i, j);
        res++;
      }
    }
  }
  return res;
}

void read_input() {
  scanf("%d %d\n", &n, &m);
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      scanf("%c", &field[i][j]);
    }
    scanf("\n");
  }
}

int main() {
  read_input();
  int ans = solve();
  printf("%d\n", ans);
  return 0;
}
