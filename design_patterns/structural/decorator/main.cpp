#include <iostream>
#include <string>

class Component
{
public:
  virtual std::string GetText() = 0;
  virtual void Display() = 0;
protected:
  Component() {}
  ~Component() {}
};

class ConcreteComponent : public Component
{
public:
  ConcreteComponent(std::string _s) {
    this->s = _s;
  }
  ConcreteComponent() {}
  ~ConcreteComponent() {}
  std::string GetText() {
    return this->s;
  }
  void Display() {
    std::cout << this->s << std::endl;
  };
private:
  std::string s;
};

class Decorator : public Component
{
protected:
  Decorator(Component* c) {
    this->_component = c;
  }
  Decorator() {}
  ~Decorator() {}
  Component* _component;
};

class ConcreteDecoratorA : public Decorator
{
public:
  ConcreteDecoratorA(Component* c) {
    this->_component = c;
  }
  ConcreteDecoratorA() {}
  ~ConcreteDecoratorA() {}
  std::string GetText() {
    return "|" + this->_component->GetText() + "|";
  }
  void Display() {
    std::cout << GetText() << std::endl;
  }
};

class ConcreteDecoratorB : public Decorator
{
public:
  ConcreteDecoratorB(Component* c) {
    this->_component = c;
  }
  ConcreteDecoratorB() {}
  ~ConcreteDecoratorB() {}
  std::string GetText() {
    return "----" + this->_component->GetText() + "----";
  }
  void Display() {
    std::cout << GetText() << std::endl;
  }
};

int main() {
  std::cout << "==== start ====" << std::endl;
  ConcreteComponent x0 = ConcreteComponent("foo");
  ConcreteDecoratorB x1 = ConcreteDecoratorB(new ConcreteComponent("foo"));
  ConcreteDecoratorA x2 = ConcreteDecoratorA(new ConcreteDecoratorB(new ConcreteComponent("foo")));
  ConcreteDecoratorB x3 = ConcreteDecoratorB(new ConcreteDecoratorA(new ConcreteDecoratorB(new ConcreteComponent("foo"))));
  x0.Display();
  x1.Display();
  x2.Display();
  x3.Display();
  std::cout << "==== end ====" << std::endl;
}
