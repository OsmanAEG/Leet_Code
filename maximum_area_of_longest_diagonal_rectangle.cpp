// LeetCode: 3000

#include <cmath>
#include <vector>

class Solution {
public:
  int areaOfMaxDiagonal(std::vector<std::vector<int>>& dimensions) {
    std::vector<int> max;
    double max_area = 0;
    double max_diagonal = 0;

    for(int i = 0; i < dimensions.size(); ++i) {
      const auto length = static_cast<double>(dimensions[i][0]);
      const auto width  = static_cast<double>(dimensions[i][1]);

      const auto area     = length*width;
      const auto diagonal = std::sqrt(length*length + width*width);

      if(diagonal > max_diagonal) {
        max_diagonal = diagonal;
        max_area = area;
        max = dimensions[i];
      } else if(diagonal == max_diagonal) {
        if(area > max_area) {
          max = dimensions[i];
          max_area = area;
        }
      }
    }

    return max_area;
  }
};