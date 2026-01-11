// LeetCode: 1925

#include <unordered_map>

class Solution {
public:
  bool is_square_triple(int a, int b, int c) {
    if(a*a + b*b == c*c) return true;
    else return false;
  }

  int countTriples(int n) {
    std::unordered_map<int, int> ab;

    int num = 0;

    for(int i = 1; i <= n; ++ i) {
      for(int j = 1; j <= n; ++j) {
        for(int k = 1; k <= n; ++k) {
          if(is_square_triple(i, j, k)) ++num;
        }
      }
    }

    return num;
  }
};