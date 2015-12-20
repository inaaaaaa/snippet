#ifndef _STATE_H_
#define _STATE_H_

#include <iostream>
#include "context.h"

class State {
 public:
  virtual void Do(Context*) {};
 protected:
  State() {};
  virtual ~State() {};
  void ChangeState(Context* c, State* s);
};

class AState : public State {
 public:
  static State* Instance();
 private:
  static State* _instance;

 public:
  void Do(Context*);
 private:
  AState() {};
  ~AState() {};
};

class BState : public State {
 public:
  static State* Instance();
 private:
  static State* _instance;

 public:
  void Do(Context*);
 private:
  BState() {};
  ~BState() {};
};
#endif
