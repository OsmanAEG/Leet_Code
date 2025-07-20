#include <iostream>
#include <vector>

class Solution {
public:
  void rotate(std::vector<std::vector<int>>& matrix) {
    int n = matrix.size();
  }
};

int main() {
  std::vector<std::vector<int>> input = {{5,1,9,11},{2,4,8,10},{13,3,6,7},{15,14,12,16}};
  Solution().rotate(input);

  for(int i = 0; i < input.size(); ++i) {
    std::cout << "[";
    for(int j = 0; j < input.size(); ++j) {
      std::cout << input[i][j] << ", ";
    }
    std::cout << "]," << std::endl;
  }

  return 0;
}