#include "singleton.h"
#include <iostream>

int main() {
  std::cout << "==== start ====" << std::endl;
  Singleton* s0 = Singleton::Instance();
  Singleton* s1 = Singleton::Instance();
  std::cout << s0 << std::endl;
  std::cout << s1 << std::endl;
  std::cout << "==== end ====" << std::endl;
}
