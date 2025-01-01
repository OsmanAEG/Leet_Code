#include<iostream>
#include<string>
#include<unordered_map>
#include<vector>

class Solution {
public:
  int numJewelsInStones(std::string jewels, std::string stones) {
    std::unordered_map<char, int> map_stones;
    int num_jewels = 0;

    for(auto& stone : stones) map_stones[stone] += 1;
    for(auto& jewel : jewels) num_jewels += map_stones[jewel];

    return num_jewels;
  }
};

int main() {
  std::string jewels = "aA";
  std::string stones = "aAAbbbb";

  const auto result = Solution().numJewelsInStones(jewels, stones);
  std::cout << result << std::endl;

  return 0;
}