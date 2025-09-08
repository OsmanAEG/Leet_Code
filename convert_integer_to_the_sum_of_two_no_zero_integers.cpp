// LeetCode: 1317

#include <string>
#include <vector>

class Solution {
public:
  bool valid(const int num) {
    const auto num_str = std::to_string(num);

    for(const auto& c : num_str) {
      if(c == '0') return false;
    }

    return true;
  }

  std::vector<int> getNoZeroIntegers(int n) {
    int low = 0;
    int high = n;

    while(low <= high) {
      if(valid(low) && valid(high) && low + high == n) {
        if(low + high == n) return {low, high};
      }

      ++low;
      --high;
    }

    return {low, high};
  }
};