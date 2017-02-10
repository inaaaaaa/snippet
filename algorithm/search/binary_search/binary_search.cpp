#include <iostream>

int BinarySearch(int* arr, int key, int min_idx, int max_idx) {
  if(max_idx < min_idx) {
    return -1; // Not Found
  }
  int mid_idx = min_idx + ((max_idx - min_idx) / 2);
  if(key < arr[mid_idx]) {
    return BinarySearch(arr, key, min_idx, mid_idx - 1);
  }
  if(key > arr[mid_idx]) {
    return BinarySearch(arr, key, mid_idx + 1, max_idx);
  }
  return mid_idx;
}

int main() {
  int arr[10] = {1, 3, 5, 11, 12, 13, 17, 22, 25, 28}; // Sorted
  for(int i = 0; i < 10; i++) {
    std::cout << "arr[" << i << "] = "<< arr[i] << std::endl;
  }
  int key = 22;
  std::cout << "key : " << key << std::endl;
  std::cout << "ans : " << BinarySearch(arr, key, 0, 9) << std::endl;
}
