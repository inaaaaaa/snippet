#include <iostream>

class Adaptee
{
public:
  void Do() {
    std::cout << "Do!!!" << std::endl;
  }
};

class Target
{
public:
  virtual void JustDoIt() = 0;
};

class Adapter : public Target
{
public:
  Adapter() {
    this->adaptee = Adaptee();
  }
  void JustDoIt() {
    this->adaptee.Do();
  }
private:
  Adaptee adaptee;
};

class Client
{
public:
  void Do() {
    Target* t = new Adapter;
    t->JustDoIt();
  }
};

int main() {
  std::cout << "==== start ====" << std::endl;
  Client c = Client();
  c.Do();
  std::cout << "==== end ====" << std::endl;
}
