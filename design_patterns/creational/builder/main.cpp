#include <iostream>
#include <string>
#include <typeinfo>

class Product0 {};
class Product1 {};
class Product2 {};

class Builder
{
public:
  virtual void BuildPartA() = 0;
  virtual void BuildPartB() = 0;
  virtual void BuildPartC() = 0;
  std::string GetResult() {
    return this->ret;
  }
protected:
  std::string ret;
};

class ConcreteBuilder : public Builder
{
public:
  virtual void BuildPartA() {
    Product0 *p = new Product0;
    ret += "[BuildPartA] ";
    ret += typeid(*p).name();
    ret += "\n";
  }
  virtual void BuildPartB() {
    Product1 *p = new Product1;
    ret += "[BuildPartB] ";
    ret += typeid(*p).name();
    ret += "\n";
  }
  virtual void BuildPartC() {
    Product2 *p = new Product2;
    ret += "[BuildPartC] ";
    ret += typeid(*p).name();
    ret += "\n";
  }
};

class Director
{
public:
  static void Construct(Builder *builder) {
    builder->BuildPartA();
    builder->BuildPartB();
    builder->BuildPartB();
    builder->BuildPartC();
    builder->BuildPartA();
    builder->BuildPartC();
  }
};

int main() {
  std::cout << "==== start ====" << std::endl;
  ConcreteBuilder *b = new ConcreteBuilder;
  Director::Construct(b);
  std::cout << b->GetResult();
  std::cout << "==== end ====" << std::endl;
}
