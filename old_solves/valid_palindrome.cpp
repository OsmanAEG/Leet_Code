#include<iostream>
#include<vector>
#include<cctype>
#include<string>

using string = std::string;

class Solution {
public:
  bool isPalindrome(string s) {
    string filtered_s;
    for(auto c : s) if(std::isalnum(c)) filtered_s += std::tolower(c);

    int idx_low = 0;
    int idx_high = filtered_s.size() - 1;

    while(idx_low < idx_high) {
      if(filtered_s[idx_low] != filtered_s[idx_high]) return false;
      ++idx_low;
      --idx_high;
    }

    return true;
  }
};

int main() {
  string s = "A man, a plan, a canal: Panama";
  const auto result = Solution().isPalindrome(s);

  if(result == 0) std::cout << "False" << std::endl;
  else std::cout << "True" << std::endl;

  return 0;
}