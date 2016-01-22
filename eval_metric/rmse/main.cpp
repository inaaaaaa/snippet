#include <cmath>
#include <iostream>

const int NUM = 100;

int f(int i) {
  return i * i;
}

// root mean square error
float calc_rmse() {
  int acc = 0;
  for(int i = 0; i < NUM; i++) {
    int predict, actual;
    std::cin >> actual;
    predict = f(i);
    acc += pow(actual - predict, 2.0);
  }
  return sqrt(acc / NUM);
}

int main() {
  float rmse = calc_rmse();
  std::cout << "rmse:" << rmse << std::endl;
}
