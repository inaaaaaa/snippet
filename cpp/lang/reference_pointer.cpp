#include <iostream>
#include <vector>

using namespace std;

// Like Java
void ref_func(vector<int> &v) {
  v.push_back(11);
}

// C style
void ptr_func(vector<int> *v) {
  (*v).push_back(22);
  v->push_back(33);
}

// This function don't change vector
void _func(vector<int> v) {
  v.push_back(44);
}

int main() {
  vector<int> v;
  ref_func(v);
  ptr_func(&v);
  _func(v);
  // v = [11, 22, 33]
  for(int i = 0; i < v.size(); ++i) {
    cout << v[i] << endl;
  }
  return 0;
}
