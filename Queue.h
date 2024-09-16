#ifndef QUEUEANDSTACK__QUEUE_H_
#define QUEUEANDSTACK__QUEUE_H_

#include "Stack.h"

// First In First Out

class Queue {
 public:
  Queue() : pushStack_(), popStack_() {}

 public:
  void push(int elem) {
    while (popStack_.top_node_) {
      pushStack_.push(popStack_.pop());
    }
    pushStack_.push(elem);
  }
  int pop() {
    while (pushStack_.top_node_) {
      popStack_.push(pushStack_.pop());
    }
    return popStack_.pop();
  }
  int &front() {
    while (pushStack_.top_node_) {
      popStack_.push(pushStack_.pop());
    }
    return popStack_.top();
  };
  int &back() {
    while (popStack_.top_node_) {
      pushStack_.push(popStack_.pop());
    }
    return pushStack_.top();
  };
  int currentMin() {
    if (pushStack_.top_node_) {
      return pushStack_.min();
    } else if (popStack_.top_node_) {
      return popStack_.min();
    }
    return 0;
  };
 private:
  Stack<int> pushStack_;
  Stack<int> popStack_;
};

#endif //QUEUEANDSTACK__QUEUE_H_
