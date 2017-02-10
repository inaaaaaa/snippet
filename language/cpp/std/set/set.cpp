#include <iostream>
#include <set>

int main() {

  std::set<int> s;

  s.insert(100);
  s.insert(100);
  s.insert(200);
  s.insert(300);
  s.insert(400);
  s.insert(400);

  // loop
  for(std::set<int>::iterator it = s.begin(); it != s.end(); ++it) {
    std::cout << *it << std::endl;
  }

  // member?
  std::set<int>::iterator it = s.find(111);
  if(it == s.end()) {
    std::cout << "Not found." << std::endl;
  } else {
    std::cout << *it << std::endl;
  }

  return 0;
}
