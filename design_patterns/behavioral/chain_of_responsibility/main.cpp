#include <iostream>

class Handler
{
public:
  virtual int HandleRequest(int query) = 0;
protected:
  Handler() {}
  Handler* _successor;
};

class ConcreteHandler0 : public Handler
{
public:
  ConcreteHandler0() {
    this->_successor = 0;
  }
  ConcreteHandler0(Handler* s) {
    this->_successor = s;
  }
  int HandleRequest(int query) {
    if(query == 0) {
      std::cout << "Handled by ConcreteHandler0" << std::endl;
      return 0;
    }
    if(this->_successor == 0) {
      std::cout << "Do nothing" << std::endl;
      return 1;
    }
    std::cout << "[chain 0 ->]" << std::endl;
    return this->_successor->HandleRequest(query);
  }
};

class ConcreteHandler1 : public Handler
{
public:
  ConcreteHandler1() {
    this->_successor = 0;
  }
  ConcreteHandler1(Handler* s) {
    this->_successor = s;
  }
  int HandleRequest(int query) {
    if(query == 1) {
      std::cout << "Handled by ConcreteHandler1" << std::endl;
      return 0;
    }
    if(this->_successor == 0) {
      std::cout << "Do nothing" << std::endl;
      return 1;
    }
    std::cout << "[chain 1 ->]" << std::endl;
    return this->_successor->HandleRequest(query);
  }
};

class Client
{
public:
  void Do(Handler* h) {
    std::cout << "- query:0" << std::endl;
    h->HandleRequest(0);
    std::cout << "- query:1" << std::endl;
    h->HandleRequest(1);
  }
};

int main() {
  std::cout << "==== start ====" << std::endl;
  Client c = Client();
  c.Do(new ConcreteHandler0(new ConcreteHandler1()));
  c.Do(new ConcreteHandler1(new ConcreteHandler0()));
  c.Do(new ConcreteHandler1());
  std::cout << "==== end ====" << std::endl;
}
