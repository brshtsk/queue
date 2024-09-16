#ifndef QUEUE__STACK_H_
#define QUEUE__STACK_H_

template<typename T>
class Node {
 public:
  Node(T elem, Node<T> *ptr) : elem_(elem), ptr_(ptr), curr_min() {
    if (ptr_) {
      curr_min = elem < ptr_->curr_min ? elem : ptr_->curr_min;
    } else {
      curr_min = elem;
    }
  }
  T curr_min;
  T elem_;
  Node<T> *ptr_;
};

// First In Last Out

template<typename T>
class Stack {
 public:
  Stack() : top_node_(nullptr) {};

 public:
  void push(T elem) {
    auto *pushed = new Node<T>(elem, top_node_);
    top_node_ = pushed;
  }
  T pop() {
    Node<T> *top_ptr = top_node_;
    T res = top_ptr->elem_;
    top_node_ = top_ptr->ptr_;
    delete top_ptr;
    return res;
  }
  T &top() {
    return top_node_->elem_;
  }
  T min() {
    return top_node_->curr_min;
  }

 private:
  Node<T> *top_node_;
  friend class Queue;
};

#endif //QUEUE__STACK_H_