#include <iostream>
#include "cassert"
#include "Stack.h"
#include "Queue.h"

int main() {
  Stack<int> stack;
  stack.push(1);
  stack.push(3);
  stack.push(-100);
  stack.push(50);
  assert(stack.top() == 50);
  assert(stack.min() == -100);
  stack.pop();
  stack.pop();
  assert(stack.min() == 1);
  assert(stack.pop() == 3);
  assert(stack.pop() == 1);

  Queue queue;
  queue.push(1);
  queue.push(3);
  queue.push(-100);
  queue.push(50);
  assert(queue.front() == 1);
  assert(queue.back() == 50);
  assert(queue.currentMin() == -100);
  queue.pop();
  queue.pop();
  queue.push(1000);
  assert(queue.pop() == -100);
  assert(queue.pop() == 50);
  assert(queue.currentMin() == 1000);
  assert(queue.pop() == 1000);
}