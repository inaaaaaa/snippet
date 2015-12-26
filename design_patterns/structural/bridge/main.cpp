#include <iostream>
#include <string>

class Implementor
{
public:
  virtual void RawOpen() = 0;
  virtual void RawPrint() = 0;
  virtual void RawClose() = 0;
protected:
  Implementor() {}
  ~Implementor() {}
};

class ConcreteImplementor : public Implementor
{
public:
  ConcreteImplementor() {}
  ~ConcreteImplementor() {}
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

class Absraction
{
public:
  Absraction() {}
  ~Absraction() {}
  Absraction(ConcreteImplementor _i) {
    this->i = _i;
  };
  void Open() {
    this->i.RawOpen();
  }
  void Print() {
    this->i.RawPrint();
  }
  void Close() {
    this->i.RawClose();
  }
  void Display() {
    this->i.RawOpen();
    this->i.RawPrint();
    this->i.RawClose();
  }
protected:
  ConcreteImplementor i;
};

class RefinedAbsraction : public Absraction
{
public:
  RefinedAbsraction() {}
  ~RefinedAbsraction() {}
  RefinedAbsraction(ConcreteImplementor _i) {
    this->i = _i;
  };
  void CountDisplay(int count) {
    Open();
    for(int i = 0; i < count; i++) {
      Print();
    }
    Close();
  }
};

int main() {
  std::cout << "==== start ====" << std::endl;
  ConcreteImplementor c0 = ConcreteImplementor("pantera");
  ConcreteImplementor c1 = ConcreteImplementor("metallica");
  Absraction a0 = Absraction(c0);
  Absraction a1 = Absraction(c1);
  RefinedAbsraction a2 = RefinedAbsraction(c0);
  a0.Print();
  a0.Display();
  a1.Display();
  a2.CountDisplay(3);
  std::cout << "==== end ====" << std::endl;
}
