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
protected:
  Target() {};
  ~Target() {};
};

class Adapter : public Target
{
public:
  Adapter() {
    this->adaptee = Adaptee();
  }
  ~Adapter() {};
  void JustDoIt() {
    this->adaptee.Do();
  }
private:
  Adaptee adaptee;
};

int main() {
  std::cout << "==== start ====" << std::endl;
  Adapter a = Adapter();
  a.JustDoIt();
  std::cout << "==== end ====" << std::endl;
}
