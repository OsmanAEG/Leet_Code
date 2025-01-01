#include<iostream>
#include<vector>
#include<map>
#include<unordered_map>

class Solution {
public:
  std::vector<int> topKFrequent(std::vector<int>& nums, int k) {
    std::vector<int> top_k_freq;

    std::unordered_map<int, int> freqs;
    std::map<int, std::vector<int>> max_freqs;

    for(auto& num : nums) freqs[num] += 1;
    for(auto& freq : freqs) max_freqs[freq.second].push_back(freq.first);

    int c = 0;
    for(auto it = max_freqs.rbegin(); it != max_freqs.rend(); ++it) {
      if(c == k) break;

      for(int i = 0; i < it->second.size(); ++i) {
        if(c == k) break;

        top_k_freq.push_back(it->second[i]);
        ++c;
      }
    }

    return top_k_freq;
  }
};

int main() {
  std::vector nums = {1, 1, 1, 2, 2, 3};
  int k = 2;

  const auto result = Solution().topKFrequent(nums, k);

  std::cout << "[";
  for(auto& num : result) {
    std::cout << num << ", ";
  }
  std::cout << "]" << std::endl;

  return 0;
}