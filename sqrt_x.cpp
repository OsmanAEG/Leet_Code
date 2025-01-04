class Solution {
public:
  long long mySqrt(long long x) {
    long long low = 0;
    long long high = x;

    while(low <= high) {
      auto mid = (low + high)/2;

      if(mid * mid > x) high = mid - 1;
      else if(mid * mid < x) low = mid + 1;
      else return mid;
    }

    return high;
  }
};