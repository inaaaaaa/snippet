#include <iostream>

float calc_error(int all, int wrong) {
  return (float) wrong / all;
}

bool p(int value, int label) {
  int expect = 0;
  if(value > 50) expect = 1;
  return expect == label;
}

int main() {
  int all, wrong;
  std::cin >> all;
  for(int i = 0; i < all; i++) {
    int value, label;
    std::cin >> value >> label;
    if(!p(value, label)) wrong++;
  }
  float error = calc_error(all, wrong);
  std::cout << "error:" << error << std::endl;
  return 0;
}
