#include <iostream>

class Subject
{
public:
  virtual void SetParam(int i) = 0;
  virtual void Do() = 0;
};

class RealSubject : public Subject
{
public:
  void SetParam(int i) {
    std::cout << "RealSubject::SetParam : " << i << std::endl;
    this->param = i;
  }
  void Do() {
    std::cout << "RealSubject::Do : " << this->param << std::endl;
  }
private:
  int param;
};

class Proxy : public Subject
{
public:
  void SetParam(int i) {
    std::cout << "Proxy::SetParam : " << i << std::endl;
    this->param = i;
  }
  void Do() {
    std::cout << "Proxy::Do" << std::endl;
    if(this->sub == 0) {
      this->sub = new RealSubject;
    }
    this->sub->SetParam(this->param);
    this->sub->Do();
  }
private:
  RealSubject* sub;
  int param;
};

class Client
{
public:
  void Do() {
    Proxy p = Proxy();
    p.SetParam(11);
    p.SetParam(22);
    p.Do();
    p.SetParam(33);
    p.SetParam(44);
    p.Do();
  }
};

int main() {
  std::cout << "==== start ====" << std::endl;
  Client c = Client();
  c.Do();
  std::cout << "==== end ====" << std::endl;
}
