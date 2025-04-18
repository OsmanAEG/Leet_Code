#include<iostream>
#include<vector>

class Solution {
public:
  int maxProfit(std::vector<int>& prices) {
    int max = 0;

    if(prices.size() < 2) return 0;

    int buy  = 0;
    int sell = 1;

    max = prices[sell] - prices[buy];

    for(int i = 1; i < prices.size(); ++i) {
      if(prices[buy] > prices[i]) {
        buy  = i;
        sell = i;
      }

      if(prices[sell] < prices[i]) sell = i;

      const int profit = prices[sell] - prices[buy];

      if(profit > max) max = profit;
    }

    return max;
  }
};

int main() {
  std::vector<int> prices = {7,1,5,3,6,4};

  const auto result = Solution().maxProfit(prices);
  std::cout << result << std::endl;

  return 0;
}