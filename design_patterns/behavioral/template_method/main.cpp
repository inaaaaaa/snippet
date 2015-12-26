#include <iostream>

class AbstractClass
{
public:
  void Execute(int count) {
    this->Initialize();
    for(int i = 0; i < count; i++) {
      this->Iterate();
    }
    this->Finalize();
  }
protected:
  AbstractClass() {}
  ~AbstractClass() {}
  virtual void Initialize() = 0;
  virtual void Iterate() = 0;
  virtual void Finalize() = 0;
};

class ConcreteClass : public AbstractClass
{
public:
  ConcreteClass() {}
  ~ConcreteClass() {}
private:
  void Initialize() {
    std::cout << "_init" << std::endl;
  }
  void Iterate() {
    std::cout << "<iter>" << std::endl;
  };
  void Finalize() {
    std::cout << "_final" << std::endl;
  }
};

int main() {
  std::cout << "==== start ====" << std::endl;
  ConcreteClass c = ConcreteClass();
  c.Execute(10);
  std::cout << "==== end ====" << std::endl;
}
