#include <iostream>

class AbstractProductB {};
class ProductB0 : public AbstractProductB {};
class ProductB1 : public AbstractProductB {};

class AbstractProductC {};
class ProductC0 : public AbstractProductC {};
class ProductC1 : public AbstractProductC {};

class AbstractProductA {
public:
  void Set(AbstractProductB* _b, AbstractProductC* _c) {
    this->b = _b;
    this->c = _c;
  }
  virtual void Echo() = 0;
private:
  AbstractProductB* b;
  AbstractProductC* c;
};
class ProductA0 : public AbstractProductA {
public:
  void Echo() {
    std::cout << "ProductA0" << std::endl;
  }
};
class ProductA1 : public AbstractProductA {
public:
  void Echo() {
    std::cout << "ProductA1" << std::endl;
  }
};

class AbstractFactory
{
public:
  virtual AbstractProductA* CreateProductA() = 0;
  virtual AbstractProductB* CreateProductB() = 0;
  virtual AbstractProductC* CreateProductC() = 0;
};

class ConcreteFactory0 : public AbstractFactory
{
public:
  AbstractProductA* CreateProductA() {
    return new ProductA0;
  }
  AbstractProductB* CreateProductB() {
    return new ProductB0;
  }
  AbstractProductC* CreateProductC() {
    return new ProductC0;
  }
};

class ConcreteFactory1 : public AbstractFactory
{
public:
  AbstractProductA* CreateProductA() {
    return new ProductA1;
  }
  AbstractProductB* CreateProductB() {
    return new ProductB1;
  }
  AbstractProductC* CreateProductC() {
    return new ProductC1;
  }
};

class Client
{
public:
  static AbstractProductA* Create(AbstractFactory *factory) {
    AbstractProductA* pa = factory->CreateProductA();
    AbstractProductB* pb = factory->CreateProductB();
    AbstractProductC* pc = factory->CreateProductC();
    pa->Set(pb, pc);
    return pa;
  }
};

int main() {
  std::cout << "==== start ====" << std::endl;
  AbstractProductA* pa0 = Client::Create(new ConcreteFactory0);
  AbstractProductA* pa1 = Client::Create(new ConcreteFactory1);
  pa0->Echo();
  pa1->Echo();
  std::cout << "==== end ====" << std::endl;
}
