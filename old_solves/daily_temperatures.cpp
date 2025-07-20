#include<iostream>
#include<stack>
#include<vector>

class Solution {
public:
  std::vector<int> dailyTemperatures(std::vector<int>& temperatures) {
    const int N = temperatures.size();

    std::stack<std::pair<int, int>> daily_temps;
    std::vector<int> days_until(N, 0);

    daily_temps.push({temperatures[0], 0});

    for(int i = 1; i < N; ++i) {
      while(daily_temps.size() > 0 && temperatures[i] > daily_temps.top().first) {
        const int top_temp = daily_temps.top().first;
        const int top_indx = daily_temps.top().second;

        days_until[top_indx] = i - top_indx;
        daily_temps.pop();
      }

      daily_temps.push({temperatures[i], i});
    }

    return days_until;
  }
};

int main() {
  std::vector<int> temps = {73,74,75,71,69,72,76,73};

  const auto result = Solution().dailyTemperatures(temps);
  for(const auto& el : result) std::cout << el << std::endl;

  return 0;
}