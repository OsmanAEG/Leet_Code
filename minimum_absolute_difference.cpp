// LeetCode: 1200

#include <algorithm>
#include <climits>
#include <vector>

class Solution {
public:
  std::vector<std::vector<int>> minimumAbsDifference(std::vector<int>& arr) {
    std::vector<std::vector<int>> pairs;

    int min_diff = INT_MAX;

    std::sort(arr.begin(), arr.end());

    for(int i = 0; i < arr.size() - 1; ++i) {
      min_diff = std::min(arr[i+1] - arr[i], min_diff);
    }

    for(int i = 0; i < arr.size() - 1; ++i) {
      if(arr[i+1] - arr[i] == min_diff) {
        pairs.push_back({arr[i], arr[i+1]});
      }
    }

    return pairs;
  }
};