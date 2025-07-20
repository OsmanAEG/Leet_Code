#include<string>

using string = std::string;

class Solution {
public:
  string makeFancyString(string s) {
    string fancy  = "";
    string triple = "";

    for(const auto& c : s) {
      if(triple.size() == 0) {
        fancy.push_back(c);
        triple.push_back(c);
      } else if(triple[0] == c  && triple.size() < 2) {
        fancy.push_back(c);
        triple.push_back(c);
      } else if(triple[0] == c  && triple.size() >= 2) {
        triple.push_back(c);
      } else {
        triple.clear();
        fancy.push_back(c);
        triple.push_back(c);
      }
    }

    return fancy;
  }
};

int main() {
  return 0;
}