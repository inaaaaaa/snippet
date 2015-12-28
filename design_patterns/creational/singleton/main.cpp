#include <iostream>

class Singleton
{
public:
  static Singleton* Instance() {
    if(_instance == 0) {
      _instance = new Singleton;
    }
    return _instance;
  };
protected:
  Singleton() {};
  ~Singleton() {};
private:
  static Singleton* _instance;
};

Singleton* Singleton::_instance = 0;

int main() {
  std::cout << "==== start ====" << std::endl;
  Singleton* s0 = Singleton::Instance();
  Singleton* s1 = Singleton::Instance();
  std::cout << s0 << std::endl;
  std::cout << s1 << std::endl;
  std::cout << "==== end ====" << std::endl;
}
