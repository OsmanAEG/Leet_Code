#include<algorithm>
#include<iostream>
#include<string>
#include<unordered_map>
#include<vector>

class Solution {
public:
  std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs) {
    std::vector<std::vector<std::string>> group_anagrams;
    std::unordered_map<std::string, std::vector<std::string>> map_anagrams;

    for(auto& str : strs) {
      auto tmp_str = str;
      std::sort(tmp_str.begin(), tmp_str.end());
      map_anagrams[tmp_str].push_back(str);
    }

    for(auto& group : map_anagrams) group_anagrams.push_back(group.second);
    return group_anagrams;
  }
};

int main() {
  std::vector<std::string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
  const auto result = Solution().groupAnagrams(strs);

  for(const auto& group : result){
    std::cout << "[ ";
    for(auto& str : group) {
      std::cout << str << ", ";
    }
    std::cout << "]" << std::endl;
  }
  return 0;
}