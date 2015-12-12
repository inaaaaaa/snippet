#include <iostream>
#include <vector>

using namespace std;

void ref_func(vector<int> &v) {
  v.push_back(11);
  v.push_back(22);
}

void ptr_func(vector<int> *v) {
  (*v).push_back(33);
  (*v).push_back(44);
  v->push_back(55);
  v->push_back(66);
}

int main() {
  vector<int> v;
  ref_func(v);
  ptr_func(&v);
  for(int i = 0; i < v.size(); ++i) {
    cout << v[i] << endl;
  }
  return 0;
}
