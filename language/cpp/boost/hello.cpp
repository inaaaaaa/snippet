#include <iostream>
#include <boost/format.hpp>

// boost compile
// g++ -I/usr/local/Cellar/boost/1.56.0/include/ -L/usr/local/Cellar/boost/1.56.0/lib/ hello.cpp

int main() {
  std::cout << boost::format("%s\n") % "Hello, World";
  return 0;
}
