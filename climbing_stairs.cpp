class Solution {
public:
  int climbStairs(int n) {
    if(n == 1) return 1;
    if(n == 2) return 2;

    int last_steps = 1;
    int steps = 2;

    int step_number = 3;

    while(step_number <= n) {
      int tmp_steps = steps;
      steps = steps + last_steps;
      last_steps = tmp_steps;
      ++step_number;
    }

    return steps;
  }
};

