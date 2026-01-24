// LeetCode: 2169

#include <algorithm>

class Solution {
public:
  int countOperations(int num1, int num2) {
    int num_operations = 0;

    while(num1 != 0 && num2 != 0) {
      if(num2 < num1) {
        std::swap(num1, num2);
      } else {
        num2 -= num1;
        ++num_operations;
      }
    }

    return num_operations;
  }
};