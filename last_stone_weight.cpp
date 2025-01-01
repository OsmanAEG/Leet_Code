#include<bits/stdc++.h>
#include<iostream>
#include<vector>

class Solution {
public:
  int lastStoneWeight(std::vector<int>& stones) {
    while(stones.size() > 1) {
      std::make_heap(stones.begin(), stones.end());

      std::pop_heap(stones.begin(), stones.end());
      const auto max1 = stones[stones.size() - 1];
      stones.pop_back();

      std::pop_heap(stones.begin(), stones.end());
      const auto max2 = stones[stones.size() - 1];
      stones.pop_back();

      if(max1 != max2) stones.push_back(max1-max2);
    }

    if(stones.size() == 0) return 0;

    return stones[0];
  }
};

int main() {
  std::vector<int> stones = {2,7,4,1,8,1};
  const auto result = Solution().lastStoneWeight(stones);

  std::cout << result << std::endl;

  return 0;
}