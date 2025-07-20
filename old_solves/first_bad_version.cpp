class Solution {
public:
  // dummy function
  bool isBadVersion(int version) { return false; }

  int firstBadVersion(int n) {
    long long low = 0;
    long long high = n;

    while(low <= high) {
      long long mid = (low + high)/2;

      if(isBadVersion(mid)) high = mid - 1;
      else low = mid + 1;
    }

    return low;
  }
};