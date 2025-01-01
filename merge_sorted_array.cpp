#include<vector>

class Solution {
public:
  void merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n) {
    int p1 = 0;
    int p2 = 0;

    int it = 0;

    std::vector<int> nums(m + n, 0);

    while(p1 < m && p2 < n) {
      if(nums1[p1] <= nums2[p2]) {
        nums[it] = nums1[p1];
        ++p1;
      } else {
        nums[it] = nums2[p2];
        ++p2;
      }

      ++it;
    }

    while(p1 < m) {
      nums[it] = nums1[p1];
      ++p1;
      ++it;
    }

    while(p2 < n) {
      nums[it] = nums2[p2];
      ++p2;
      ++it;
    }

    nums1 = nums;
  }
};