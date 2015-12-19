#ifndef _STATE_H_
#define _STATE_H_

#include <iostream>

class State {
 public:
  virtual void Do() {};
  virtual State* next() { return new State(); };
 protected:
  State() {};
  virtual ~State() {};
};

class AState : public State {
 public:
  static State* Instance();
 private:
  static State* _instance;

 public:
  void Do();
  State* next();
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
  void Do();
  State* next();
 private:
  BState() {};
  ~BState() {};
};
#endif
