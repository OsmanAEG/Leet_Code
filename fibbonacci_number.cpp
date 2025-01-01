class Solution {
public:
  int fib(int n) {
    if(n == 0) return 0;
    if(n == 1) return 1;

    int last_num = 0;
    int num = 1;

    for(int i = 1; i < n; ++i) {
      int tmp_num = num;
      num = num + last_num;
      last_num = tmp_num;
    }

    return num;
  }
};