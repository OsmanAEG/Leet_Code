// LeetCode: 1518

class Solution {
public:
  int numWaterBottles(int numBottles, int numExchange) {
    int num_drink = 0;
    int num_empty = 0;

    while(numBottles != 0) {
      --numBottles;

      ++num_drink;
      ++num_empty;

      if(num_empty == numExchange) {
        num_empty = 0;
        ++numBottles;
      }
    }

    return num_drink;
  }
};