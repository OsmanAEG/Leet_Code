#include<iostream>
#include<stack>
#include<string>
#include<vector>

using string = std::string;

class Solution {
public:
  int calPoints(std::vector<string>& operations) {
    std::stack<int> track;

    for(const auto& op : operations) {
      if(op == "+") {
        const auto b = track.top();
        track.pop();
        const auto a = track.top();
        track.pop();
        track.push(a);
        track.push(b);
        track.push(a + b);
      } else if(op == "D") {
        const auto a = track.top();
        track.push(a*2);
      } else if(op == "C") {
        track.pop();
      } else {
        track.push(std::stoi(op));
      }
    }

    int score = 0;

    while(track.size() != 0) {
      score += track.top();
      track.pop();
    }

    return score;
  }
};

int main() {
  std::vector<string> ops = {"5","-2","4","C","D","9","+","+"};
  const auto result = Solution().calPoints(ops);

  std::cout << result << std::endl;

  return 0;
}