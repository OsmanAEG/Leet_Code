#include <string>

class Solution {
public:
  int possibleStringCount(std::string word) {
    int mult = 1;

    int idx = 0;

    auto c = word[idx];

    while(idx < word.size() - 1) {
      int num_it = 0;

      while(c == word[idx + 1]) {
        ++idx;
        ++num_it;
      }

      ++idx;
      mult += num_it;
      c = word[idx];
    }

    return mult;
  }
};