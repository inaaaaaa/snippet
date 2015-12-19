#ifndef _CONTEXT_H_
#define _CONTEXT_H_

#include "state.h"

class Context {
 public:
  Context();
  void Request();

  /*private:
    friend class State;
    void ChangeState(State*);*/

 private:
  State* _state;
};
#endif
