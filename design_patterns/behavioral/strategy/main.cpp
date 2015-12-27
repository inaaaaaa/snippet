#include <iostream>

class Context;

class Strategy
{
public:
  virtual void Forecast(Context*) = 0;
protected:
  Strategy() {}
  ~Strategy() {}
};

class Context
{
public:
  Context(int i, Strategy* s);
  Context();
  ~Context();
  void Forecast();
  int GetVal();
  void SetVal(int i);
  void ChangeStrategy(Strategy* s);
private:
  int val;
  Strategy* strategy;
};

class AggressiveStrategy : public Strategy
{
public:
  AggressiveStrategy();
  ~AggressiveStrategy();
  void Forecast(Context* c);
};

class ConservativeStrategy : public Strategy
{
public:
  ConservativeStrategy();
  ~ConservativeStrategy();
  void Forecast(Context* c);
};

AggressiveStrategy::AggressiveStrategy() {}
AggressiveStrategy::~AggressiveStrategy() {}
void AggressiveStrategy::Forecast(Context* c) {
  int next = c->GetVal() + 5;
  std::cout << "[AggressiveStrategy] " << next << std::endl;
  c->SetVal(next);
  if(next > 50) {
    c->ChangeStrategy(new ConservativeStrategy);
  }
}

ConservativeStrategy::ConservativeStrategy() {}
ConservativeStrategy::~ConservativeStrategy() {}
void ConservativeStrategy::Forecast(Context* c) {
  int next = c->GetVal() - 3;
  std::cout << "[ConservativeStrategy] " << next << std::endl;
  c->SetVal(next);
  if(next <= 50) {
    c->ChangeStrategy(new AggressiveStrategy);
  }
}

Context::Context(int i, Strategy* s) {
    this->val = i;
    this->strategy = s;
}
Context::Context() {}
Context::~Context() {}
void Context::Forecast() {
  this->strategy->Forecast(this);
}
int Context::GetVal() {
  return this->val;
}
void Context::SetVal(int i) {
  this->val = i;
}
void Context::ChangeStrategy(Strategy* s) {
  this->strategy = s;
}

int main() {
  std::cout << "==== start ====" << std::endl;
  Context c = Context(30, new AggressiveStrategy);
  for(int i = 0; i < 10; i++) {
    c.Forecast();
  }
  std::cout << "==== end ====" << std::endl;
}
