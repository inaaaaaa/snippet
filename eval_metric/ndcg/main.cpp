#include <cmath>
#include <iostream>
#include <vector>

float calc_dcg(std::vector<int>& vec) {
  float acc = vec[0];
  for(int i = 1; i < vec.size(); i++) {
    acc += vec[i] / ((float)log(i + 1) / log(2));
  }
  return acc;
}

// NOT call by reference
float calc_ideal(std::vector<int> vec) {
  sort(vec.begin(), vec.end(), std::greater<int>());
  return calc_dcg(vec);
}

// Normalized Discounted Cumulative Gain
float calc_ndcg(std::vector<int>& vec) {
  return calc_dcg(vec) / calc_ideal(vec);
}

int main() {
  std::vector<int> vec;
  int num_data, value;
  std::cin >> num_data;
  for(int i = 0; i < num_data; i++) {
    std::cin >> value;
    vec.push_back(value);
  }
  std::cout << "  dcg:" << calc_dcg(vec) << std::endl;
  std::cout << "ideal:" << calc_ideal(vec) << std::endl;
  std::cout << " ndcg:" << calc_ndcg(vec) << std::endl;
  return 0;
}
