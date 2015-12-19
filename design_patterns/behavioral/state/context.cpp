#include "context.h"
#include "state.h"
#include <iostream>

Context::Context() {
  this->_state = AState::Instance();
}

void Context::Request() {
  this->_state->Do();
  this->_state = this->_state->next();
}
