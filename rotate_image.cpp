#include <algorithm>
#include <iostream>
#include <vector>

class Solution {
public:
  void rotate(std::vector<std::vector<int>>& matrix) {
    const int N = matrix.size();

    for(int i = 0; i < N - 1; ++i) {
      for(int j = i + 1; j < N; ++j) {
        std::swap(matrix[i][j], matrix[j][i]);
      }
    }

    for(int i = 0; i < N; ++i) {
      int low = 0;
      int high = N-1;

      while(low <= high) {
        std::swap(matrix[i][low], matrix[i][high]);
        ++low;
        --high;
      }
    }
  }
};

int main() {
  std::vector<std::vector<int>> matrix = {{5,1,9,11},{2,4,8,10},{13,3,6,7},{15,14,12,16}};

  Solution().rotate(matrix);
  const int N = matrix.size();

  for(int i = 0; i < matrix.size(); ++i) {
    std::cout << "[";
    for(int j = 0; j < matrix.size(); ++j) {
      std::cout << matrix[i][j] << " ";
    }

    std::cout << "]" << std::endl;
  }
}