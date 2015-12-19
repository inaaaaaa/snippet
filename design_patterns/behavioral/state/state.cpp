#include "state.h"

State::State() {
}

AState::AState() {
}

AState* AState::Instance() {
  if(AState::_instance == 0) {
    AState::_instance = new AState;
  }
  return AState::_instance;
}

void AState::Handle() {
  std::cout << "AState" << std::endl;
}

AState* AState::_instance = 0;
