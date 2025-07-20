#include<algorithm>
#include<iostream>
#include<vector>

class Solution {
public:
  int maxArea(std::vector<int>& height) {
    int l = 0;
    int h = height.size() - 1;

    int max_area = 0;

    while(l < h) {
      const auto length = std::min(height[l], height[h]);
      const auto area = length*(h-l);

      max_area = std::max(area, max_area);

      if(height[l] < height[h]) ++l;
      else --h;
    }

    return max_area;
  }
};

int main() {
  std::vector<int> input = {1,8,6,2,5,4,8,3,7};

  const auto result = Solution().maxArea(input);
  std::cout << result << std::endl;

  return 0;
}