#include<string>
#include<vector>

using string = std::string;

class Solution {
public:
  int countSeniors(std::vector<string>& details) {
    int sum = 0;
    for(const auto& p : details) {
      int age = (int)(p[11] - '0');
      age = age*10 + (int)(p[12] - '0');

      if(age > 60) ++sum;
    }
    return sum;
  }
};

int main() {
  return 0;
}