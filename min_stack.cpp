#include<climits>
#include<iostream>
#include<vector>

class MinStack {
public:
  std::vector<int> min;
  std::vector<int> idx;

  MinStack() { min.push_back(INT_MAX); }

  void push(int val) {
    min.push_back(std::min(min.back(), val));
    idx.push_back(val);
  }

  void pop() {
    min.pop_back();
    idx.pop_back();
  }

  int top()    { return idx.back(); }
  int getMin() { return min.back(); }
};