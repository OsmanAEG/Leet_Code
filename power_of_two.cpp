// LeetCode: 231

class Solution {
public:
  bool isPowerOfTwo(int n) {
    if(n <= 0) return false;
    if(n == 1) return true;

    long long result = 1;

    while(result < n) result *= 2;

    if(result == n) return true;

    return false;
  }
};