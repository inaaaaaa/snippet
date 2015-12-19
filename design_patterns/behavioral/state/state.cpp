#include "state.h"

/* AState */
State* AState::Instance() {
  if(AState::_instance == 0) {
    AState::_instance = new AState;
  }
  return AState::_instance;
}

void AState::Do() {
  std::cout << "AState" << std::endl;
}

State* AState::next() {
  return BState::Instance();
}

State* AState::_instance = 0;

/* BState */
State* BState::Instance() {
  if(BState::_instance == 0) {
    BState::_instance = new BState;
  }
  return BState::_instance;
}

void BState::Do() {
  std::cout << "BState" << std::endl;
}

State* BState::next() {
  return AState::Instance();
}

State* BState::_instance = 0;
