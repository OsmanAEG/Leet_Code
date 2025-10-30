// LeetCode: 66

#include <vector>

class Solution {
public:
  std::vector<int> plusOne(std::vector<int>& digits) {
    bool done_sum = false;

    for(int i = digits.size() - 1; i >= 0; --i) {
      if(digits[i] < 9) {
        digits[i] += 1;
        done_sum = true;
        break;
      } else {
        digits[i] = 0;
      }
    }

    if(!done_sum) {
      digits.insert(digits.begin(), 1);
    }

    return digits;
  }
};