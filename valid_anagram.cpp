#include<iostream>
#include<map>

class Solution {
public:
  bool isAnagram(std::string s, std::string t) {
    if(s.size() != t.size()) return false;

    std::map<int, int> check1;
    std::map<int, int> check2;

    for(int i = 0; i < s.size(); ++i) {
      check1[s[i]] += 1;
      check2[t[i]] += 1;
    }

    if(check1 != check2) return false;

    return true;
  }
};

int main() {
  std::string s = "anagram";
  std::string t = "nagaram";

  const auto result = Solution().isAnagram(s, t);
  std::cout << result << std::endl;

  return 0;
}