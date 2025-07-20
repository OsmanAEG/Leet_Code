#include<iostream>
#include<vector>

class Solution {
public:
  void reverseString(std::vector<char>& s) {
    int idx_low = 0;
    int idx_high = s.size()-1;

    while(idx_low < idx_high) {
      const char tmp = s[idx_low];
      s[idx_low]  = s[idx_high];
      s[idx_high] = tmp;

      ++idx_low;
      --idx_high;
    }
  }
};

int main() {
  std::vector<char> input = {'h','e','l','l','o'};
  Solution().reverseString(input);

  for(int i = 0; i < input.size(); ++i) {
    std::cout << input[i] << std::endl;
  }

  return 0;
}