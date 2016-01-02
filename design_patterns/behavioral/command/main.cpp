#include <iostream>

class Receiver
{
public:
  void Action() {
    std::cout << "Action" << std::endl;
  }
};

class Command
{
public:
  virtual void Execute() = 0;
};

class ConcreteCommand : public Command
{
public:
  void SetReceiver(Receiver* receiver) {
    this->_receiver = receiver;
  }
  void SetState(int state) {
    this->_state = state;
  }
  void Execute() {
    for(int i = 0; i < this->_state; i++) {
      this->_receiver->Action();
    }
  }
private:
  Receiver* _receiver;
  int _state;
};

class Invoker
{
public:
  void StoreCommand(Command* command) {
    this->_command = command;
  }
  void Fire() {
    _command->Execute();
  }
private:
  Command* _command;
};

class Client
{
public:
  Command* GetConcreteCommand(Receiver* receiver, int state) {
    ConcreteCommand* cc = new ConcreteCommand;
    cc->SetReceiver(receiver);
    cc->SetState(state);
    return cc;
  }
};

int main() {
  std::cout << "==== start ====" << std::endl;

  // Get a command
  Client client = Client();
  Command* command = client.GetConcreteCommand(new Receiver, 3);

  // Set an event
  Invoker invoker = Invoker();
  invoker.StoreCommand(command);

  // Fire
  invoker.Fire();

  std::cout << "==== end ====" << std::endl;
}
