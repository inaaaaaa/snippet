#ifndef _REAL_SUBJECT_H_
#define _REAL_SUBJECT_H_

#include "subject.h"

class RealSubject : public Subject {
 public:
  RealSubject();
  ~RealSubject() {};
  void SetParam(int i);
  void Do();

 private:
  int param;
};
#endif
