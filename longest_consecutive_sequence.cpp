#include<iostream>
#include<vector>
#include<map>

class Solution {
public:
  int longestConsecutive(std::vector<int>& nums) {
    std::map<int, int> my_map;
    int max_len  = 1;
    int tmp_len  = 1;
    int prev_num = 0;

    for(auto& num : nums) my_map[num] += 1;

    auto it = my_map.begin();

    if(it == my_map.end()) return 0;

    prev_num = it->first;
    ++it;

    for(; it != my_map.end(); ++it) {
      auto curr_num = it->first;

      if(curr_num - prev_num == 1) ++tmp_len;
      else tmp_len = 1;

      if(tmp_len > max_len) max_len = tmp_len;
      prev_num = curr_num;
    }

    return max_len;
  }
};

int main() {
  std::vector<int> nums = {};
  const auto result = Solution().longestConsecutive(nums);

  std::cout << result << std::endl;

  return 0;
}