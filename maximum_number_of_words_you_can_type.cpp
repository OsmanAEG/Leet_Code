// LeetCode: 1935

#include <string>
#include <unordered_set>

class Solution {
public:
  bool keys_in_word(std::string& word, std::string& letters) {
    std::unordered_set<char> set;
    for(const auto& c : letters) set.insert(c);

    for(const auto& c : word) {
      if(set.find(c) != set.end()) {
        return false;
      }
    }

    return true;
  }

  int canBeTypedWords(std::string text, std::string brokenLetters) {
    int idx = 0;
    std::string word = "";
    int num_valid_words = 0;

    while(idx < text.size()) {
      if(text[idx] == ' ') {
        if(keys_in_word(word, brokenLetters)) ++num_valid_words;
        word = "";
      } else {
        word += text[idx];
      }

      ++idx;
    }

    if(keys_in_word(word, brokenLetters)) ++num_valid_words;

    return num_valid_words;
  }
};