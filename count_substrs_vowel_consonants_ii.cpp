#include <unordered_map>
#include <string>

class Solution {
public:
  long long countOfSubstrings(std::string word, int k) {
    int num_valid_subs = 0;
    int num_consonants = 0;

    std::unordered_map<char, int> vowels;

    int min = 0;
    int max = 1;

    while(max < word.size()) {
      const auto& c = word[j];

      if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
        vowels[c] += 1;
      } else {
        ++num_consonants;
      }

      if(vowels.size() == 5 && num_consonants == k) {
        ++num_valid_subs;
      } else if(num_consonants > k) {
        break;
      }
    }

    return num_valid_subs;
  }
};