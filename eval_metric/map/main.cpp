#include <iostream>
#include <vector>

struct Data
{
  Data() {}
  ~Data() {}
  Data(int rank, int label) {
    this->rank = rank;
    this->label = label;
  }
  // ascending order
  bool operator<(const Data& another) const {
    return rank < another.rank;
  }
  int rank;
  int label;
};

float calc_p(int tp, int fp) {
  return (float) tp / (tp + fp);
}

float calc_ap(float acc_p, int tp) {
  return acc_p / tp;
}

// Mean average precision
float calc_map(std::vector<Data>& vec) {
  sort(vec.begin(), vec.end());
  float acc_p = 0.0f, acc_ap = 0.0f;
  int tp = 0, fp = 0;
  for(int i = 0; i < vec.size(); i++) {
    if(vec[i].label == 0) {
      fp++;
    } else {
      tp++;
      acc_p += calc_p(tp, fp);
      acc_ap += calc_ap(acc_p, tp);
    }
  }
  return acc_ap / tp;
}

int main() {
  std::vector<Data> vec;
  int num_data, rank, label;
  std::cin >> num_data;
  for(int i = 0; i < num_data; i++) {
    std::cin >> rank >> label;
    vec.push_back(Data(rank, label));
  }
  float map = calc_map(vec);
  std::cout << "map:" << map << std::endl;
  return 0;
}
