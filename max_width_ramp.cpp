#include<iostream>
#include<vector>

class Solution {
public:
  int maxWidthRamp(std::vector<int>& nums) {
    int N = nums.size();

    int max_ramp = 0;
    std::vector<int> max_ahead(N, nums[N - 1]);

    for(int i = N - 2; i >= 0; --i) max_ahead[i] = std::max(max_ahead[i+1], nums[i]);

    int i = 0;

    for(int j = 1; j < N; ++j) {
      while(i < j && nums[i] > max_ahead[j]) ++i;
      max_ramp = std::max(max_ramp, j - i);
    }

    return max_ramp;
  }
};

int main() {
  std::vector<int> nums = {3,1,2};

  const auto result = Solution().maxWidthRamp(nums);
  std::cout << result << std::endl;

  return 0;
}