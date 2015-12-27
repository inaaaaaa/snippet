#include <iostream>

class Product
{
public:
  virtual void Echo() = 0;
protected:
  Product() {}
  ~Product() {}
};

class ConcreteProductA : public Product
{
public:
  ConcreteProductA() {}
  ~ConcreteProductA() {}
  void Echo() {
    std::cout << "[ConcreteProductA]" << std::endl;
  }
};

class ConcreteProductB : public Product
{
public:
  ConcreteProductB() {}
  ~ConcreteProductB() {}
  void Echo() {
    std::cout << "[ConcreteProductB]" << std::endl;
  }
};

class Creator
{
public:
  virtual Product* DoMakeProduct() = 0;
  void Create() {
    Product* p = DoMakeProduct();
    std::cout << "Creator::Create" << std::endl;
    p->Echo();
  }
protected:
  Creator() {}
  ~Creator() {}
};

class ConcreteCreatorA : public Creator
{
public:
  ConcreteCreatorA() {}
  ~ConcreteCreatorA() {}
  Product* DoMakeProduct() {
    return new ConcreteProductA;
  }
};

class ConcreteCreatorB : public Creator
{
public:
  ConcreteCreatorB() {}
  ~ConcreteCreatorB() {}
  Product* DoMakeProduct() {
    return new ConcreteProductB;
  }
};

int main() {
  std::cout << "==== start ====" << std::endl;
  ConcreteCreatorA ca = ConcreteCreatorA();
  ca.Create();
  ConcreteCreatorB cb = ConcreteCreatorB();
  cb.Create();
  std::cout << "==== end ====" << std::endl;
}
