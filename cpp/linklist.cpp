#include <iostream>

struct Node
{
  Node() {}
  Node(int v, Node *next) {
    this->v = v;
    this->next = next;
  }

  static Node* Array2LinkList(int *arr, int size) {
    Node *ret = new Node(arr[0], NULL);
    if(size < 2) {
      return ret;
    }
    Node *now = ret;
    for(int i = 1; i < size; i++) {
      now->next = new Node(arr[i], NULL);
      now = now->next;
    }
    return ret;
  }

  void Print() {
    std::cout << this->v << " ";
    if(this->next != NULL) {
      this->next->Print();
    } else {
      std::cout << std::endl;
    }
  }

  int v;
  Node *next;
};

int main() {
  Node *a = new Node(0, new Node(1, new Node(2, NULL)));
  int arr[] = {4, 3, 2, 6, 5};
  Node *b = Node::Array2LinkList(arr, 5);
  a->Print();
  b->Print();
}
