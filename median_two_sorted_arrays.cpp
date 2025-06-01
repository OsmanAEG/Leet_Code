#include <vector>

class Solution {
public:
  double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2) {
    int ptr1 = 0;
    int ptr2 = 0;

    std::vector<int> nums_total;

    while(ptr1 < nums1.size() && ptr2 < nums2.size()) {
      if(nums1[ptr1] <= nums2[ptr2]) {
        nums_total.push_back(nums1[ptr1]);
        ++ptr1;
      } else {
        nums_total.push_back(nums2[ptr2]);
        ++ptr2;
      }
    }

    if(ptr1 == nums1.size()) {
      while(ptr2 < nums2.size()) {
        nums_total.push_back(nums2[ptr2]);
        ++ptr2;
      }
    } else {
      while(ptr1 < nums1.size()) {
        nums_total.push_back(nums1[ptr1]);
        ++ptr1;
      }
    }

    int mid = nums_total.size()/2;

    if(nums_total.size()%2 != 0) {
      return static_cast<double>(nums_total[mid]);
    } else {
      return 0.5*(static_cast<double>(nums_total[mid - 1]) + static_cast<double>(nums_total[mid]));
    }
  }
};