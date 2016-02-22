#include <iostream>
#include <string>
#include <tuple>

// compile : clang++ -std=c++11 tuple.cpp

std::tuple<bool, std::string> func(int val) {
  if (val == 10) {
    return std::make_tuple(true, "ok");
  } else {
    return std::make_tuple(false, "error");
  }
}

int main() {
  std::tuple<bool, std::string> foo = func(10);
  std::cout << std::get<0>(foo) << std::endl;
  std::cout << std::get<1>(foo) << std::endl;

  std::tuple<bool, std::string> bar = func(1);
  std::cout << std::get<0>(bar) << std::endl;
  std::cout << std::get<1>(bar) << std::endl;

  return 0;
}
