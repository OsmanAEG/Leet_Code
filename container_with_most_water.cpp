// LeetCode: 11

#include <algorithm>
#include <vector>

class Solution {
public:
  int maxArea(std::vector<int>& height) {
    int max_area = 0;

    int low = 0;
    int high = height.size() - 1;

    while(low < high) {
      const int b = high - low;
      const int h = std::min(height[low], height[high]);

      const int area = b*h;

      max_area = std::max(max_area, area);

      if(height[low] < height[high]) {
        ++low;
      } else {
        --high;
      }
    }

    return max_area;
  }
};
