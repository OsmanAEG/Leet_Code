// int guess(int num) {
//   return 0;
// }

class Solution {
public:
  long long guessNumber(long long n) {
    long long low = 0;
    long long high = n;

    while(low <= high) {
      long long mid = (low + high)/2;

      if(guess(mid) < 0) high = mid - 1;
      else if(guess(mid) > 0) low = mid + 1;
      else return mid;
    }

    return low;
  }
};