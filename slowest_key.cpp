#include <string>
#include <vector>

class Solution {
public:
  char slowestKey(std::vector<int>& releaseTimes, std::string keysPressed) {
    int max = 0;
    char max_char;
    int time_pressed = 0;

    for(int i = 0; i < keysPressed.size(); ++i) {
      if(releaseTimes[i] - time_pressed > max) {
        max = releaseTimes[i] - time_pressed;
        max_char = keysPressed[i];
      } else if(releaseTimes[i] - time_pressed == max) {
        if(keysPressed[i] > max_char) max_char = keysPressed[i];
      }

      time_pressed = releaseTimes[i];
    }

    return max_char;
  }
};