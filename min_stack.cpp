// LeetCode: 155

#include <algorithm>
#include <climits>
#include <vector>

class MinStack {
public:
  std::vector<int> stack;
  std::vector<int> min_stack;
  int min = INT_MAX;

  MinStack() {
  }

  void push(int val) {
    stack.push_back(val);
    min = std::min(min, val);
    min_stack.push_back(min);
  }

  void pop() {
    if(stack.size() > 0) {
      stack.pop_back();
      min_stack.pop_back();
    }

    if(stack.size() <= 0) {
      min = INT_MAX;
    } else {
      min = min_stack[min_stack.size() - 1];
    }
  }

  int top() {
    return stack[stack.size() - 1];
  }

  int getMin() {
    return min;
  }
};