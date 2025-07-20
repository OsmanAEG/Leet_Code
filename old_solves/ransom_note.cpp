#include<string>
#include<iostream>
#include<unordered_map>

class Solution {
public:
  bool canConstruct(std::string ransomNote, std::string magazine) {
    std::unordered_map<char, int> dict;

    for(const auto& c : magazine) dict[c] += 1;

    for(const auto& c : ransomNote) {
      dict[c] -= 1;
      if(dict[c] < 0) return false;
    }

    return true;
  }
};

int main() {
  std::string ransomNote = "a";
  std::string magazine   = "b";

  const auto result = Solution().canConstruct(ransomNote, magazine);
  std::cout << result << std::endl;
}