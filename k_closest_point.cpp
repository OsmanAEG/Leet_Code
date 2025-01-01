#include<iostream>
#include<map>
#include<vector>

class Solution {
public:
  std::vector<std::vector<int>> kClosest(std::vector<std::vector<int>>& points, int k) {
    std::map<int, std::vector<int>> sqr_dist_idx;
    std::vector<std::vector<int>> closest;

    for(int i = 0; i < points.size(); ++i) {
      const auto x = points[i][0];
      const auto y = points[i][1];

      const auto sqr_dist = x*x + y*y;

      sqr_dist_idx[sqr_dist].push_back(i);
    }

    int c = 0;

    for(auto it = sqr_dist_idx.begin(); it != sqr_dist_idx.end(); ++it) {
      if(c == k) break;

      for(int i = 0; i < it->second.size(); ++i) {
        if(c == k) break;

        closest.push_back(points[it->second[i]]);
        ++c;
      }
    }

    return closest;
  }
};

int main() {
  std::vector<std::vector<int>> input = {{1,3},{-2,2}};
  int k = 1;

  const auto result = Solution().kClosest(input, k);

  return 0;
}