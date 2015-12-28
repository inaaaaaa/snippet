#include <iostream>
#include <map>
#include <string>

class FlyWeight
{
public:
  virtual std::string Operation(int extrinsic) = 0;
};

class ConcreteFlyWeight : public FlyWeight
{
public:
  ConcreteFlyWeight(std::string s) {
    this->intrinsicState = s;
  }
  std::string Operation(int extrinsicState) {
    switch(extrinsicState) {
    case 0:
      return "**" + this->intrinsicState + "**";
    case 1:
      return "_" + this->intrinsicState + "_";
    case 2:
      return "~~" + this->intrinsicState + "~~";
    default:
      return "";
    }
  }
private:
  std::string intrinsicState;
};

class FlyWeightFactory
{
public:
  FlyWeight* GetFlyWeight(std::string key) {
    if(flyweight.count(key)) {
      return flyweight[key];
    } else {
      FlyWeight* f = new ConcreteFlyWeight(key);
      flyweight.insert(std::map<std::string, FlyWeight*>::value_type(key, f));
      return f;
    }
  }
private:
  std::map<std::string, FlyWeight*> flyweight;
};

class Client
{
public:
  void Do() {
    FlyWeightFactory ff = FlyWeightFactory();
    FlyWeight* f[5];
    f[0] = ff.GetFlyWeight("A");
    f[1] = ff.GetFlyWeight("A");
    f[2] = ff.GetFlyWeight("B");
    f[3] = ff.GetFlyWeight("B");
    f[4] = ff.GetFlyWeight("B");
    for(int i = 0; i < 5; i++) {
      std::cout << f[i] << " : " << f[i]->Operation(i % 3) << std::endl;
    }
  }
};

int main() {
  std::cout << "==== start ====" << std::endl;
  Client c = Client();
  c.Do();
  std::cout << "==== end ====" << std::endl;
}
