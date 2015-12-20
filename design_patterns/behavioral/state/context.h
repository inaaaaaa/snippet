#ifndef _CONTEXT_H_
#define _CONTEXT_H_

class State;

class Context {
 public:
  Context();
  ~Context() {};
  void Do();

 private:
  friend class State;
  void ChangeState(State*);
  State* _state;
};
#endif
