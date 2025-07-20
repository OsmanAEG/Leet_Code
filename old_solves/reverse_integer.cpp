class Solution {
public:
  long long reverse(long long x) {
    bool neg = (x < 0) ? true : false;

    if(neg) x *= -1;

    long long rev_x = 0;

    while(x > 0) {
      long long res = x%10;

      rev_x *= 10;
      rev_x += res;

      x /= 10;
    }

    if(neg) rev_x *= -1;

    if(rev_x <= -2147483648 || rev_x >= 2147483648 - 1) return 0;

    return rev_x;
  }
};