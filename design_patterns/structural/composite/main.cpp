#include <iostream>
#include <vector>

class Component
{
public:
  virtual void Operation() {}
  virtual void Add(Component*) {}
  virtual void Remove(Component*) {}
  virtual Component* GetChild(int) {
    return 0;
  }
};

class Leaf : public Component
{
public:
  Leaf(int _i) {
    this->i = _i;
  }
  void Operation() {
    std::cout << "Leaf:" << this->i << std::endl;
  }
private:
  int i;
};

class Composite : public Component
{
public:
  void Operation() {
    for(int i = 0; i < children.size(); i++) {
      children.at(i)->Operation();
    }
  }
  void Add(Component* c) {
    children.push_back(c);
  }
  void Remove(Component* c) {
    children.erase(remove(children.begin(), children.end(), c), children.end());
  }
  Component* GetChild(int i) {
    return children.at(i);
  }
private:
  std::vector<Component*> children;
};

class Client
{
public:
  void Do() {
    Component *c0 = new Composite;
    Component *c1 = new Composite;
    Component *c2 = new Composite;
    c0->Add(new Leaf(0));
    c0->Add(new Leaf(1));
    c0->Add(new Leaf(2));
    c0->Add(new Leaf(3));
    c0->Add(new Leaf(4));
    c1->Add(new Leaf(11));
    c1->Add(new Leaf(22));
    c1->Add(new Leaf(33));
    c2->Add(new Leaf(111));
    c2->Add(new Leaf(222));
    c0->Add(c1);
    c0->Add(c2);
    c0->Remove(c2);
    c0->Operation();
  }
};

int main() {
  std::cout << "==== start ====" << std::endl;
  Client c = Client();
  c.Do();
  std::cout << "==== end ====" << std::endl;
}
