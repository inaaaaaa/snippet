#ifndef _CONTEXT_H_
#define _CONTEXT_H_

#include "state.h"

class Context {
 public:
  Context();
  ~Context() {};
  void Request();

 private:
  State* _state;
};
#endif
