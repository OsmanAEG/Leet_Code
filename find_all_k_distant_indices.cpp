#include <algorithm>
#include <vector>

class Solution {
public:
  std::vector<int> findKDistantIndices(std::vector<int>& nums, int key, int k) {
    std::vector<int> k_distant_idx;
    std::vector<int> k_distant_vals;

    for(int i = 0; i < nums.size(); ++i) {
      if(nums[i] == key) {
        k_distant_idx.push_back(i);
      }
    }

    for(int i = 0; i < nums.size(); ++i) {
      for(const auto& j : k_distant_idx) {
        if(std::abs(i-j) <= k) {
          k_distant_vals.push_back(i);
          break;
        }
      }
    }

    std::sort(k_distant_vals.begin(), k_distant_vals.end());

    return k_distant_vals;
  }
};