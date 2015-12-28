#include <iostream>
#include <string>

class Implementor
{
public:
  virtual void RawOpen() = 0;
  virtual void RawPrint() = 0;
  virtual void RawClose() = 0;
};

class ConcreteImplementor : public Implementor
{
public:
  ConcreteImplementor(std::string _s) {
    this->s = _s;
    this->width = _s.length();
  };
  void RawOpen() {
    this->PrintLine();
  }
  void RawPrint() {
    std::cout << "|" + this->s + "|" << std::endl;
  }
  void RawClose() {
    this->PrintLine();
  }
private:
  std::string s;
  int width;
  void PrintLine() {
    std::cout << "+";
    for(int i = 0; i < this->width; i++) {
      std::cout << "-";
    }
    std::cout << "+" << std::endl;
  }
};

class Abstraction
{
public:
  Abstraction() {}
  Abstraction(ConcreteImplementor *_impl) {
    this->impl = _impl;
  }
  void Open() {
    this->impl->RawOpen();
  }
  void Print() {
    this->impl->RawPrint();
  }
  void Close() {
    this->impl->RawClose();
  }
  void Display() {
    this->impl->RawOpen();
    this->impl->RawPrint();
    this->impl->RawClose();
  }
protected:
  ConcreteImplementor *impl;
};

class RefinedAbstraction : public Abstraction
{
public:
  RefinedAbstraction(ConcreteImplementor *_impl) {
    this->impl = _impl;
  }
  void CountDisplay(int cnt) {
    this->Open();
    for(int i = 0; i < cnt; i++) {
      this->Print();
    }
    this->Close();
  }
};

int main() {
  std::cout << "==== start ====" << std::endl;
  Abstraction a0 = Abstraction(new ConcreteImplementor("pantera"));
  Abstraction a1 = Abstraction(new ConcreteImplementor("metallica"));
  RefinedAbstraction a2 = RefinedAbstraction(new ConcreteImplementor("pantera"));
  a0.Print();
  a0.Display();
  a1.Display();
  a2.CountDisplay(3);
  std::cout << "==== end ====" << std::endl;
}
