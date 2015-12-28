#include <iostream>
#include <string>

class Component
{
public:
  virtual std::string GetText() = 0;
  void Display() {
    std::cout << this->GetText() << std::endl;
  }
};

class ConcreteComponent : public Component
{
public:
  ConcreteComponent(std::string _s) {
    this->s = _s;
  }
  std::string GetText() {
    return this->s;
  }
private:
  std::string s;
};

class Decorator : public Component
{
protected:
  Decorator() {}
  Component* _component;
};

class ConcreteDecoratorA : public Decorator
{
public:
  ConcreteDecoratorA(Component* c) {
    this->_component = c;
  }
  std::string GetText() {
    return "|" + this->_component->GetText() + "|";
  }
};

class ConcreteDecoratorB : public Decorator
{
public:
  ConcreteDecoratorB(Component* c) {
    this->_component = c;
  }
  std::string GetText() {
    return "****" + this->_component->GetText() + "****";
  }
};

int main() {
  std::cout << "==== start ====" << std::endl;
  Component* x0 = new ConcreteComponent("foo");
  Component* x1 = new ConcreteDecoratorB(new ConcreteComponent("foo"));
  Component* x2 = new ConcreteDecoratorA(new ConcreteDecoratorB(new ConcreteComponent("foo")));
  Component* x3 = new ConcreteDecoratorB(new ConcreteDecoratorA(new ConcreteDecoratorB(new ConcreteComponent("foo"))));
  x0->Display();
  x1->Display();
  x2->Display();
  x3->Display();
  std::cout << "==== end ====" << std::endl;
}
