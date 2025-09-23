// LeetCode: 165

#include <string>
#include <vector>

class Solution {
public:
  std::vector<int> get_version_nums(std::string version) {
    std::vector<int> version_nums;

    int idx = 0;
    std::string word = "";

    while(idx < version.size()) {
      if(version[idx] != '.') {
        word += version[idx];
      } else {
        version_nums.push_back(std::stoi(word));
        word = "";
      }

      ++idx;
    }

    version_nums.push_back(std::stoi(word));

    return version_nums;
  }

  int compareVersion(std::string version1, std::string version2) {
    const auto version1_nums = get_version_nums(version1);
    const auto version2_nums = get_version_nums(version2);

    int idx = 0;

    while(idx < version1_nums.size() && idx < version2_nums.size()) {
      if(version1_nums[idx] < version2_nums[idx]) return -1;
      if(version1_nums[idx] > version2_nums[idx]) return 1;

      ++idx;
    }

    if(version1_nums.size() > version2_nums.size()) {
      while(idx < version1_nums.size()) {
        if(version1_nums[idx] != 0) return 1;
        ++idx;
      }
    } else {
      while(idx < version2_nums.size()) {
        if(version2_nums[idx] != 0) return -1;
        ++idx;
      }
    }

    return 0;
  }
};