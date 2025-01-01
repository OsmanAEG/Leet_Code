#include<vector>
#include<iostream>

class Solution {
public:
  std::vector<int> sortedSquares(std::vector<int>& nums) {
    std::vector<int> result(nums.size());
    for(int i = 0; i < nums.size(); ++i) nums[i] *= nums[i];

    int end = nums.size() - 1;
    int start = 0;
    int c = 0;

    while(start <= end) {
      if(nums[end] > nums[start]) {
        result[c] = nums[end];
        --end;
      } else {
        result[c] = nums[start];
        ++start;
      }

      ++c;
    }

    end = nums.size() - 1;
    start = 0;

    while(start <= end) {
      const int tmp = result[start];
      result[start] = result[end];
      result[end] = tmp;
      --end;
      ++start;
    }

    return result;
  }
};

int main() {
  std::vector<int> input = {-4, 1, 0, 3, 10};

  const auto result = Solution().sortedSquares(input);

  for(int i = 0; i < result.size(); ++i) {
    std::cout << result[i] << std::endl;
  }

  return 0;
}