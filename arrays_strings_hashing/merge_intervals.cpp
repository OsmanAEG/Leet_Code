#include<iostream>
#include<vector>
#include<algorithm>

class Solution {
public:
  std::vector<std::vector<int>> merge(std::vector<std::vector<int>>& intervals) {
    const int N = intervals.size();
    if(N == 1) return intervals;

    std::vector<std::vector<int>> merged_intervals;
    std::sort(intervals.begin(), intervals.end());

    merged_intervals.push_back(intervals[0]);

    for(int i = 1; i < intervals.size(); ++i) {
      const auto& new_pair  = intervals[i];
      auto& last_pair = merged_intervals[merged_intervals.size() - 1];

      if(last_pair[1] < new_pair[0]) merged_intervals.push_back(new_pair);
      else if(last_pair[1] <= new_pair[1]) last_pair[1] = new_pair[1];
    }

    return merged_intervals;
  }
};

int main() {
  std::vector<std::vector<int>> intervals = {{1,3},{2,6},{8,10},{15,18}};

  const auto result = Solution().merge(intervals);

  for(const auto& pair : result) {
    std::cout << "[" << pair[0] << ", " << pair[1] << "], " << std::endl;
  }

  return 0;
}