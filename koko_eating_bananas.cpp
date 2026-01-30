// LeetCode: 875

#include <algorithm>
#include <vector>

class Solution {
public:
  int minEatingSpeed(std::vector<int>& piles, int h) {
    std::sort(piles.begin(), piles.end());

    int slow = 1;
    int fast = piles[piles.size() - 1];

    int k = fast;

    while(slow <= fast) {
      int check_k = (slow + fast)/2;

      long long time = 0;

      for(int i = 0; i < piles.size(); ++i) {
        time += (piles[i] + check_k - 1)/check_k;
      }

      if(time <= h) {
        k = check_k;
        fast = check_k - 1;
      } else {
        slow = check_k + 1;
      }
    }

    return k;
  }
};