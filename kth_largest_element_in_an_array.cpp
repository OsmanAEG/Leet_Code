#include<bits/stdc++.h>
#include<iostream>
#include<vector>

class Solution {
public:
  int findKthLargest(std::vector<int>& nums, int k) {
    int largest = 0;

    while(k > 0) {
      std::make_heap(nums.begin(), nums.end());
      std::pop_heap(nums.begin(), nums.end());

      largest = nums[nums.size() - 1];
      nums.pop_back();

      k -= 1;
    }

    return largest;
  }
};

int main() {
  std::vector<int> nums = {3,2,3,1,2,4,5,5,6};
  int k = 4;

  const auto result = Solution().findKthLargest(nums, k);
  std::cout << result << std::endl;

  return 0;
}