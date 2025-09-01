// LeetCode: 739

#include <stack>
#include <vector>

class Solution {
public:
	std::vector<int> dailyTemperatures(std::vector<int>& temperatures) {
		std::vector<int> days_until;
		std::stack<int> reverse_temps;

		days_until.resize(temperatures.size());

		for(int i = temperatures.size() - 1; i >= 0; --i) {
			days_until[i] = 0;

			while(!reverse_temps.empty()) {
				const auto temp_i = temperatures[i];
				const auto temp_top = temperatures[reverse_temps.top()];

				if(temp_top > temp_i) {
					days_until[i] = reverse_temps.top() - i;
					break;
				} else {
					reverse_temps.pop();
				}
			}

			reverse_temps.push(i);
		}

		return days_until;
	}
};