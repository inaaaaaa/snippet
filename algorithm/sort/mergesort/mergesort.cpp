#include <iostream>

int mergesort(int *lst, int idx0, int idx1);
int merge(int *lst, int idx00, int idx01, int idx10, int idx11);
int swap(int *lst, int x, int y);

int mergesort(int *lst, int idx0, int idx1) {
  if((idx1 - idx0) < 2) return 0;
  int mid = (idx0 + idx1) / 2;
  mergesort(lst, idx0, mid);
  mergesort(lst, mid, idx1);
  merge(lst, idx0, mid, mid, idx1);
  return 0;
}

int merge(int *lst, int idx00, int idx01, int idx10, int idx11) {
  int a = idx00;
  int b = idx10;
  while(true) {
    if(a == idx01) return 0;
    if(lst[b] < lst[a]) swap(lst, a, b);
    a++;
  }
}

int swap(int *lst, int x, int y) {
  int tmp = lst[x];
  lst[x] = lst[y];
  lst[y] = tmp;
  return 0;
}

int main() {
  int lst[] = {33, 22, 55, 44, 11, 66, 0, 99};
  int size = sizeof(lst) / sizeof(lst[0]);
  mergesort(lst, 0, size);
  for(int i = 0; i < size; i++) {
    std::cout << lst[i] << std::endl;
  }
  return 0;
}
