#include<string>

using string = std::string;

class Solution {
public:
  bool check_valid(string s, bool forward) {
    int low = 0;
    int high = s.size() - 1;

    int num_err = 0;

    while(low < high) {
      if(s[low] != s[high]) {
        ++num_err;

        if(forward) ++low;
        else --high;
      } else {
        ++low;
        --high;
      }

      if(num_err > 1) break;
    }

    if(num_err > 1) return false;
    else return true;
  }

  bool validPalindrome(string s) {
    return check_valid(s, true) || check_valid(s, false);
  }
};