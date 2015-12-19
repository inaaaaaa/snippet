#include "context.h"
#include "state.h"

#include <iostream>

Context::Context() {
  this->_state = AState::Instance();
}

void Context::Request() {
  this->_state->Handle();
}
