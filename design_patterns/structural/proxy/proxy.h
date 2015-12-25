#ifndef _PROXY_H_
#define _PROXY_H_

#include "subject.h"
#include "real_subject.h"

class Proxy : public Subject {
 public:
  Proxy();
  ~Proxy() {};
  void SetParam(int i);
  void Do();

 private:
  RealSubject* sub;
  int param;
};
#endif
