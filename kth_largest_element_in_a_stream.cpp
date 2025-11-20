// LeetCode: 703

#include <queue>
#include <vector>

class KthLargest {
public:
  KthLargest(int k, std::vector<int>& nums) {
    kth = k;

    for(const auto& num : nums) {
      min_heap.push(num);
      if(min_heap.size() > kth) min_heap.pop();
    }
  }

  int add(int val) {
    min_heap.push(val);
    if(min_heap.size() > kth) min_heap.pop();
    return min_heap.top();
  }

private:
  int kth;
  std::priority_queue<int, std::vector<int>, std::greater<int>> min_heap;
};