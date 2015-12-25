#include <iostream>
#include "proxy.h"

int main() {
  std::cout << "==== start ====" << std::endl;
  Proxy p = Proxy();
  p.SetParam(11);
  p.SetParam(22);
  p.Do();
  p.SetParam(33);
  p.SetParam(44);
  p.Do();
  p.Do();
  std::cout << "==== end ====" << std::endl;
}
