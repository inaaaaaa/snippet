#include "context.h"
#include "state.h"
#include <iostream>

Context::Context() {
  this->_state = AState::Instance();
}

void Context::Do() {
  this->_state->Do(this);
}

void Context::ChangeState(State* s) {
  this->_state = s;
}
