#include <iostream>
#include <string>
#include <vector>

class Iterator;

class Aggregate
{
public:
  virtual Iterator* CreateIterator() = 0;
  virtual void Add(std::string) = 0;
  virtual std::string At(int) = 0;
  virtual int Count() = 0;
};

class Iterator
{
public:
  virtual void First() = 0;
  virtual void Next() = 0;
  virtual bool IsDone() = 0;
  virtual std::string CurrentItem() = 0;
protected:
  Aggregate* _agg;
  int _current;
};

class ConcreteIterator : public Iterator
{
public:
  ConcreteIterator(Aggregate* agg) {
    this->_agg = agg;
  }
  void First() {
    this->_current = 0;
  }
  void Next() {
    this->_current++;
  }
  bool IsDone() {
    return this->_current >= this->_agg->Count();
  }
  std::string CurrentItem() {
    return this->_agg->At(this->_current);
  }
};

class ConcreteAggregate : public Aggregate
{
public:
  Iterator* CreateIterator() {
    return new ConcreteIterator(this);
  }
  void Add(std::string s) {
    v.push_back(s);
  }
  std::string At(int i) {
    return v.at(i);
  }
  int Count() {
    return this->v.size();
  }
private:
  std::vector<std::string> v;
};

class Client
{
public:
  void Do() {
    ConcreteAggregate ca = ConcreteAggregate();
    ca.Add("one");
    ca.Add("two");
    ca.Add("three");
    Iterator* i = ca.CreateIterator();
    for(i->First(); !i->IsDone(); i->Next()) {
      std::cout << i->CurrentItem() << std::endl;
    }
  }
};

int main() {
  std::cout << "==== start ====" << std::endl;
  Client c = Client();
  c.Do();
  std::cout << "==== end ====" << std::endl;
}
