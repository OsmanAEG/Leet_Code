#include<vector>

class Solution {
public:
  int minCostClimbingStairs(std::vector<int>& cost) {
    if(cost.size() == 0) return 0;
    if(cost.size() == 1) return cost[0];
    if(cost.size() == 2) return std::min(cost[0], cost[1]);

    int step = 2;
    int last_paid = cost[0];
    int paid = cost[1];

    while(step < cost.size()) {
      const int cost_two_step = last_paid + cost[step];
      const int cost_one_step = paid + cost[step];

      last_paid = paid;

      if(cost_two_step < cost_one_step) paid = cost_two_step;
      else paid = cost_one_step;

      ++step;
    }

    return std::min(paid, last_paid);
  }
};