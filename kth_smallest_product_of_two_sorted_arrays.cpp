#include <algorithm>
#include <vector>

class Solution {
public:
  long long kthSmallestProduct(std::vector<int>& nums1, std::vector<int>& nums2, long long k) {
    std::vector<long long> smallest;

    for(int i = 0; i < nums1.size(); ++i) {
      for(int j = 0; j < nums2.size(); ++j) {
        const long long result = static_cast<long long>(nums1[i])*static_cast<long long>(nums2[j]);
        smallest.push_back(result);
      }
    }

    std::sort(smallest.begin(), smallest.end());

    return smallest[k-1];
  }
};