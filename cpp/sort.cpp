#include <iostream>
#include <vector>

class Foo
{
public:
  ~Foo() {}
  Foo() {}
  Foo(int x) {
    this->x = x;
  }
  int getX() {
    return this->x;
  }
private:
  int x;
};

bool foo(Foo* l, Foo* r) {
  return l->getX() < r->getX();
}

int main() {
  std::vector<Foo*> v;
  v.push_back(new Foo(5));
  v.push_back(new Foo(3));
  v.push_back(new Foo(9));
  v.push_back(new Foo(1));
  v.push_back(new Foo(2));

  for (int i = 0; i < v.size(); i++) {
    std::cout << v.at(i)->getX() << " ";
  }
  std::cout << std::endl;

  std::sort(v.begin(), v.end(), foo);

  for (int i = 0; i < v.size(); i++) {
    std::cout << v.at(i)->getX() << " ";
  }
  std::cout << std::endl;
}
