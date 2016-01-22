#include <iostream>
#include <vector>

struct Data
{
  Data() {}
  ~Data() {}
  Data(int value, int label) {
    this->value = value;
    this->label = label;
  }
  // ascending order
  bool operator<(const Data& another) const {
    return value > another.value;
  }
  int value;
  int label;
};

float calc_auc(std::vector<Data>& vec) {
  sort(vec.begin(), vec.end());

  int num_pos = 0, num_neg = 0;
  for(int i = 0; i < vec.size(); i++) {
    if(vec[i].label == 1) {
      num_pos++;
    } else {
      num_neg++;
    }
  }

  float auc = 0.0f, pos = 0.0f;
  float pos_step = 1.0f / num_pos, neg_step = 1.0f / num_neg;
  for(int i = 0; i < vec.size(); i++) {
    if(vec[i].label == 1) {
      pos += pos_step;
    } else {
      auc += pos * neg_step;
    }
  }

  return auc;
}

int main() {
  std::vector<Data> vec;
  int num_data, value, label;
  std::cin >> num_data;
  for(int i = 0; i < num_data; i++) {
    std::cin >> value >> label;
    vec.push_back(Data(value, label));
  }
  float auc = calc_auc(vec);
  std::cout << "auc:" << auc << std::endl;
  return 0;
}
