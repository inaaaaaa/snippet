class Singleton {
 public:
  static Singleton* Instance();
 protected:
  Singleton() {};
  ~Singleton() {};
 private:
  static Singleton* _instance;
};
