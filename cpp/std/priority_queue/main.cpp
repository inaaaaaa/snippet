#include <iostream>
#include <queue>

std::priority_queue <int> max_pq;
std::priority_queue <int, std::vector<int>, std::greater<int> > min_pq;

int main() {
  std::cout << "==== max priority queue ====" << std::endl;
  max_pq.push(11);
  max_pq.push(33);
  max_pq.push(22);
  std::cout << max_pq.top() << std::endl;
  max_pq.pop();
  std::cout << max_pq.top() << std::endl;
  max_pq.pop();
  std::cout << max_pq.top() << std::endl;
  max_pq.pop();

  std::cout << "==== min priority queue ====" << std::endl;
  min_pq.push(11);
  min_pq.push(33);
  min_pq.push(22);
  std::cout << min_pq.top() << std::endl;
  min_pq.pop();
  std::cout << min_pq.top() << std::endl;
  min_pq.pop();
  std::cout << min_pq.top() << std::endl;
  min_pq.pop();
}
