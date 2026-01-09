#include <vector>

class Solution {
public:
  int alternatingSum(std::vector<int>& nums) {
    int sum = 0;

    int i = 0;

    while(i < nums.size() - 1) {
      sum += nums[i];
      sum -= nums[i+1];
      i += 2;
      std::cout << sum << std::endl;
    }

    i -= 1;

    std::cout << i << std::endl;

    if(i%2 == 0) sum += nums[i];
    else sum -= nums[i];

    return sum;
  }
};