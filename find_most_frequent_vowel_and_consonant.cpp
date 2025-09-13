// LeetCode: 3541

#include <algorithm>
#include <string>
#include <unordered_map>

class Solution {
public:
  bool is_vowel(const char& c) {
    if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
      return true;
    } else {
      return false;
    }
  }

  int maxFreqSum(std::string s) {
    std::unordered_map<char, int> vowels;
    std::unordered_map<char, int> consonants;

    int max_num_vowel = 0;
    int max_num_consonant = 0;

    for(const auto& c : s) {
      if(is_vowel(c)) {
        vowels[c] += 1;
        max_num_vowel = std::max(max_num_vowel, vowels[c]);
      } else {
        consonants[c] += 1;
        max_num_consonant = std::max(max_num_consonant, consonants[c]);
      }
    }

    return max_num_vowel + max_num_consonant;
  }
};