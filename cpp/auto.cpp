#include <iostream>
#include <vector>

// compile : clang++ -std=c++11 lambda.cpp

int main() {
  auto a = 1;
  std::cout << a << std::endl;
  
  std::vector<int> v{1, 3, 5, 7, 2, 4, 6};
  for (auto x: v) {
    std::cout << x << std::endl;
  }
  return 0;
}
