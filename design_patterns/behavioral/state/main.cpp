#include "context.h"
#include <iostream>

int main() {
  std::cout << "==== start ====" << std::endl;
  Context c;
  c.Do();
  c.Do();
  c.Do();
  c.Do();
  std::cout << "==== end ====" << std::endl;
  return 0;
}
