#include<iostream>
#include<queue>
#include<string>
#include<vector>

using string = std::string;

class Solution {
public:
  string longestDiverseString(int a, int b, int c) {
    string happy = "";

    std::priority_queue<std::pair<int, char>> max_heap;

    if(a > 0) max_heap.push({a, 'a'});
    if(b > 0) max_heap.push({b, 'b'});
    if(c > 0) max_heap.push({c, 'c'});

    while(max_heap.size() != 0) {
      const int n = happy.size();
      auto [n1_size, n1] = max_heap.top();
      max_heap.pop();

      if(n > 1 && n1 == happy[n - 1] && n1 == happy[n - 2]) {
        if(max_heap.empty()) break;

        auto [n2_size, n2] = max_heap.top();
        max_heap.pop();

        happy += n2;
        --n2_size;

        if(n2_size > 0) max_heap.push({n2_size, n2});

        max_heap.push({n1_size, n1});
      } else {
        happy += n1;
        --n1_size;

        if(n1_size > 0) max_heap.push({n1_size, n1});
      }
    }

    return happy;
  }
};

int main() {
  const auto result = Solution().longestDiverseString(1, 1, 7);

  std::cout << result << std::endl;

  return 0;
}