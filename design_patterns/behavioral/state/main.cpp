#include "context.h"
#include <iostream>

int main() {
  std::cout << "==== start ====" << std::endl;
  Context c;
  c.Request();
  c.Request();
  c.Request();
  c.Request();
  std::cout << "==== end ====" << std::endl;
  return 0;
}
