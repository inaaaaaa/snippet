#ifndef _STATE_H_
#define _STATE_H_

#include <iostream>

class State {
 public:
  virtual void Handle();
  State();
};

class AState : public State {
 public:
  static AState* Instance();
  void Handle();
 protected:
  AState();
 private:
  static AState* _instance;
};

#endif
