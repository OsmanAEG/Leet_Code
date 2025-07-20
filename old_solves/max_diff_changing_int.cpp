#include <string>

class Solution {
public:
  int maxDiff(int num) {
    auto num1_str = std::to_string(num);
    auto num2_str = std::to_string(num);

    char val = 'x';

    for(int i = 0; i < num1_str.size(); ++i) {
      if(val == 'x' && num1_str[i] != '9') {
        val = num1_str[i];
      }

      if(num1_str[i] == val) {
        num1_str[i] = '9';
      }
    }

    val = 'x';

    if(num2_str[0] == '1') {
      for(int i = 1; i < num2_str.size(); ++i) {
        if(val == 'x' && num2_str[i] != '0' && num2_str[i] != '1') {
          val = num2_str[i];
        }

        if(num2_str[i] == val) {
          num2_str[i] = '0';
        }
      }
    } else {
      val = num2_str[0];

      for(int i = 0; i < num2_str.size(); ++i) {
        if(num2_str[i] == val) {
          num2_str[i] = '1';
        }
      }
    }

    const auto num1 = std::stoi(num1_str);
    const auto num2 = std::stoi(num2_str);

    return num1 - num2;
  }
};