#include <iostream>
#include "real_subject.h"

RealSubject::RealSubject() {
  std::cout << "RealSubject::RealSubject" << std::endl;
}

void RealSubject::SetParam(int i) {
  std::cout << "RealSubject::SetParam : " << i << std::endl;
  this->param = i;
}

void RealSubject::Do() {
  std::cout << "RealSubject::Do : " << this->param << std::endl;
}
