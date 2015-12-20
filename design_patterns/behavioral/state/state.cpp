#include "state.h"

/* State */
void State::ChangeState(Context* c, State* s) {
  c->ChangeState(s);
}


/* AState */
State* AState::_instance = 0;
State* AState::Instance() {
  if(AState::_instance == 0) {
    AState::_instance = new AState;
  }
  return AState::_instance;
}

void AState::Do(Context* c) {
  std::cout << "AState" << std::endl;
  ChangeState(c, BState::Instance());
}


/* BState */
State* BState::_instance = 0;
State* BState::Instance() {
  if(BState::_instance == 0) {
    BState::_instance = new BState;
  }
  return BState::_instance;
}

void BState::Do(Context* c) {
  std::cout << "BState" << std::endl;
  ChangeState(c, AState::Instance());
}
