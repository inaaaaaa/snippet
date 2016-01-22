#include <cstdlib>
#include <ctime>
#include <iostream>

const int NUM = 100;

int f(int i) {
  int r0 = rand() % 3;
  int r1 = rand() % 5;
  return (i + r0) * (i + r1);
}

int main() {
  srand(time(NULL));
  for(int i = 0; i < NUM; i++) {
    std::cout << f(i) << std::endl;
  }
}
