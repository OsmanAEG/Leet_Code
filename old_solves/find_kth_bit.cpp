#include<algorithm>
#include<iostream>
#include<string>

using string = std::string;

class Solution {
public:
  string reverse(string input) {
    std::reverse(input.begin(), input.end());
    return input;
  }

  string invert(string input) {
    for(int i = 0; i < input.size(); ++i) {
      if(input[i] == '0') input[i] = '1';
      else input[i] = '0';
    }

    return input;
  }

  char findKthBit(int n, int k) {
    string S_im1 = "0";

    for(int i = 1; i < n; ++i) {
      string S = S_im1 + "1" + reverse(invert(S_im1));
      S_im1 = S;
    }

    return S_im1[k-1];
  }
};

int main() {
  int n = 3;
  int k = 1;

  const auto result = Solution().findKthBit(n, k);
  std::cout << result << std::endl;

  return 0;
}