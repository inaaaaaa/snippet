#include <iostream>

/* euclidean_algorithm */
int gcd(int x, int y) {
  int rem = x % y;
  if(rem == 0) {
    return y;
  } else {
    return gcd(y, rem);
  }
}

int main() {
  std::cout << gcd(9, 6) << std::endl;
  std::cout << gcd(1071, 1029) << std::endl;
}
