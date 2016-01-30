#include <algorithm>
#include <cmath>
#include <iostream>
#include <queue>
#include <vector>

const int MAX_M = 100; // record
const int MAX_N = 100; // feature

int M, N;
int label[MAX_M];
int feature[MAX_M][MAX_N];

struct Node
{
  Node() {}
  ~Node() {}
  Node(int f_id) {
    this->f_id = f_id;
  }

  bool isLeaf() {
    return left == NULL && right == NULL;
  }

  std::vector<int> member;
  int f_id;
  float criteria;
  Node* left;
  Node* right;
};

bool all(std::vector<int>& vec, int n) {
  for(int i = 0; i < vec.size(); i++) {
    if(label[vec[i]] != n) return false;
  }
  return true;
}

void pprint(Node* n, int indent) {
  std::string ind = "";
  for(int i = 0; i < indent; i++) {
    ind += "  ";
  }
  std::cout << ind << std::flush;
  if(n->isLeaf()) {
    std::cout << " member:" << std::flush;
    for(int i = 0; i < n->member.size(); i++) {
      std::cout << n->member[i] << " " << std::flush;
    }
  } else {
    std::cout << "[f" << n->f_id << " < " << n->criteria << "?]"<< std::flush;
  }
  std::cout << std::endl;
  if(n->left != NULL) pprint(n->left, (indent + 1));
  if(n->right != NULL) pprint(n->right, (indent + 1));
}

float calc_cost(std::vector<int>& vec, int s, int e) {
  float ave = 0.0f;
  for(int i = s; i < e; i++) {
    ave += vec[i];
  }
  ave = ave / (e - s);
  float res = 0.0f;
  for(int i = s; i < e; i++) {
    res += sqrt(pow(vec[i] - ave, 2));
  }
  return res;
}

int decide_criteria(int fea) {
  int criteria = 0;
  float min = 10000;
  std::vector<int> vec;
  for(int rec = 0; rec < M; rec++) {
    vec.push_back(feature[rec][fea]);
  }
  std::sort(vec.begin(), vec.end());
  for(int rec = 1; rec < M - 1; rec++) {
    float x = calc_cost(vec, 0, rec) + calc_cost(vec, rec, M); // 遊離度

    if(x < min) {
      criteria = vec[rec];
      min = x;
    }
  }
  return criteria;
}

Node* construct() {
  std::queue<Node*> que;
  Node* root = new Node(0);
  for(int rec = 0; rec < M; rec++) {
    root->member.push_back(rec);
  }
  que.push(root);

  while(!que.empty()) {
    Node* n = que.front();
    que.pop();

    if((n->member.size() < 2) or all(n->member, 0) or all(n->member, 1)) {
      continue;
    }

    n->criteria = decide_criteria(n->f_id);

    Node* ln = new Node(n->f_id + 1);
    Node* rn = new Node(n->f_id + 1);

    for(int j = 0; j < n->member.size(); j++) {
      if(feature[n->member[j]][n->f_id] < n->criteria) {
        ln->member.push_back(n->member[j]);
      } else {
        rn->member.push_back(n->member[j]);
      }
    }
    n->left = ln;
    n->right = rn;
    que.push(ln);
    que.push(rn);
  }
  return root;
}

int main() {
  std::cin >> M >> N;
  for(int i = 0; i < M; i++) {
    std::cin >> label[i];
    for(int j = 0; j < N; j++) {
      std::cin >> feature[i][j];
    }
  }
  Node* root = construct();
  pprint(root, 0);
}
