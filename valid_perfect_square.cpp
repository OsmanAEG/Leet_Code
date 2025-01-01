class Solution {
public:
  bool isPerfectSquare(int num) {
    long long num_long = num;
    long long low = 0;
    long long high = (num_long + 2)/2;

    while(low <= high) {
      long long mid = (low + high)/2;

      if(mid*mid > num) high = mid - 1;
      else if(mid*mid < num) low = mid + 1;
      else return true;
    }

    return false;
  }
};