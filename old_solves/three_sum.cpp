#include<algorithm>
#include<iostream>
#include<vector>

class Solution {
public:
  std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
    std::vector<std::vector<int>> triplets;

    std::sort(nums.begin(), nums.end());

    for(int i = 0; i < nums.size(); ++i) {
      int l = i+1;
      int h = nums.size() - 1;

      if(nums[i] > 0) break;
      if(i > 0 && nums[i] == nums[i-1]) continue;

      while(l < h) {
        const int sum = nums[l] + nums[i] + nums[h];

        if(sum == 0) {
          triplets.push_back({nums[l], nums[i], nums[h]});
          ++l;
          --h;
          while(l < h && nums[l] == nums[l-1]) ++l;
          while(h > l && nums[h] == nums[h+1]) --h;
        } else if(sum < 0) {
          ++l;
        } else if(sum > 0) {
          --h;
        }
      }
    }

    return triplets;
  }
};

int main() {
  std::vector<int> nums = {-1,0,1,2,-1,-4};

  const auto result = Solution().threeSum(nums);

  for(int i = 0; i < result.size(); ++i) {
    std::cout << "{" << result[i][0] << ", "
                     << result[i][1] << ", "
                     << result[i][2] << "}" << std::endl;
  }

  return 0;
}