#include <string>

class Solution {
public:
  char kthCharacter(int k) {
    std::string word = "a";

    while(word.size() < k) {
      std::string addition = "";

      for(int i = 0; i < word.size(); ++i) {
        if(word[i] == 'z') {
          addition.push_back('a');
        } else {
          addition.push_back(word[i] + 1);
        }
      }

      word += addition;
    }

    return word[k-1];
  }
};