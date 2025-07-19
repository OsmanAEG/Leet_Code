#include <string>
#include <unordered_set>
#include <vector>

class Solution {
public:
  std::vector<std::string> removeSubfolders(std::vector<std::string>& folder) {
    std::vector<std::string> no_sub_folders;
    std::unordered_set<std::string> dirs;

    for(const auto& sub_folder : folder) dirs.insert(sub_folder);

    for(const auto& sub_folder : folder) {
      std::string path;
      bool remove_sub_folder = false;

      for(int i = 0; i < sub_folder.size() - 1; ++i) {
        const auto& c = sub_folder[i];
        path += c;

        if(path.size() < sub_folder.size()
            && dirs.find(path) != dirs.end()
            && sub_folder[i+1] == '/') {
          remove_sub_folder = true;
        }
      }

      if(!remove_sub_folder) {
        no_sub_folders.push_back(sub_folder);
      }
    }

    return no_sub_folders;
  }
};