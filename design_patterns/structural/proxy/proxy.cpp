#include <iostream>
#include "proxy.h"

Proxy::Proxy() {
  std::cout << "Proxy::Proxy" << std::endl;
  sub = 0;
}

void Proxy::SetParam(int i) {
  std::cout << "Proxy::SetParam : " << i << std::endl;
  this->param = i;
}

void Proxy::Do() {
  std::cout << "Proxy::Do" << std::endl;
  if(this->sub == 0) {
    this->sub = new RealSubject;
  }
  this->sub->SetParam(this->param);
  this->sub->Do();
}
