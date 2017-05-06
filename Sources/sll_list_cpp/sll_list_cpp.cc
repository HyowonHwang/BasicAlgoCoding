#include <iostream>
#include <memory>

template <typename T>
struct Node {
  T data_;
  struct Node* next_; 
};

template <typename T>
void AddNode(Node* head, T data) {
  Node<T> *new_node = new Node<T>;
  new_node->data_ = data;
  new_node->next = nullptr;
  
  if(!head) {
    head = new_node;
    return;
  }
    
  Node<T> *cursor = head;

  while(cursor->next){
    cursor = cursor->next;
  }
  
}
