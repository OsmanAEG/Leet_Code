#include <string>
#include <vector>

class Solution {
public:
  std::vector<std::string> happy_strs;

  void find_happy_strings(std::string happy_str, int n) {
    if(happy_str.size() == n) {
      happy_strs.push_back(happy_str);
    } else {
      if(happy_str.back() == 'a') {
        find_happy_strings(happy_str + 'b', n);
        find_happy_strings(happy_str + 'c', n);
      } else if(happy_str.back() == 'b') {
        find_happy_strings(happy_str + 'a', n);
        find_happy_strings(happy_str + 'c', n);
      } else {
        find_happy_strings(happy_str + 'a', n);
        find_happy_strings(happy_str + 'b', n);
      }
    }
  }

  std::string getHappyString(int n, int k) {
    find_happy_strings("a", n);
    find_happy_strings("b", n);
    find_happy_strings("c", n);

    if(happy_strs.size() < k) {
      return "";
    }

    return happy_strs[k-1];
  }
};