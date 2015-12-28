#include <iostream>
#include <map>
#include <string>

class Prototype
{
public:
  virtual Prototype* Clone() = 0;
protected:
  Prototype() {}
  ~Prototype() {}
};

class ConcretePrototype : public Prototype
{
public:
  ConcretePrototype(std::string _s) {
    this->s = _s;
  }
  ConcretePrototype() {}
  ~ConcretePrototype() {}
  Prototype* Clone() {
    return new ConcretePrototype(*this);
  }
private:
  ConcretePrototype(ConcretePrototype *other) {
    this->s = other->s;
  }
  std::string s;
};

class Client
{
public:
  Client() {}
  ~Client() {}
  void Register(std::string key, Prototype* p) {
    m[key] = p;
  }
  Prototype* Create(std::string key) {
    return m[key]->Clone();
  }
private:
  std::map<std::string, Prototype*> m;
};

int main() {
  std::cout << "==== start ====" << std::endl;
  Client c = Client();
  Prototype* p0 = new ConcretePrototype("foo");
  Prototype* p1 = new ConcretePrototype("bar");
  c.Register("foo", p0);
  c.Register("bar", p1);
  std::cout << "[foo] " << p0 << std::endl;
  std::cout << "[foo] " << c.Create("foo") << std::endl;
  std::cout << "[foo] " << c.Create("foo") << std::endl;
  std::cout << "[foo] " << c.Create("foo") << std::endl;
  std::cout << "[bar] " << p1 << std::endl;
  std::cout << "[bar] " << c.Create("bar") << std::endl;
  std::cout << "[bar] " << c.Create("bar") << std::endl;
  std::cout << "[bar] " << c.Create("bar") << std::endl;
  std::cout << "==== end ====" << std::endl;
}
