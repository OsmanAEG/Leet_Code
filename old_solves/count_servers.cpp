#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

class Solution {
public:
  int countServers(std::vector<std::vector<int>>& grid) {
    size_t num_servers = 0;

    size_t M = grid.size();
    size_t N = grid[0].size();

    for(size_t i = 0; i < M; ++i) {
      for(size_t j = 0; j < N; ++j) {
        if(grid[i][j] == 1) ++num_servers;
      }
    }

    std::set<int> row_servers;
    std::set<int> col_servers;

    // loop through rows
    for(size_t i = 0; i < M; ++i) {

      std::set<int> row_servers_i;

      for(size_t j = 0; j < N; ++j) {
        if(grid[i][j] == 1) row_servers_i.insert(i*N + j);
      }

      if(row_servers_i.size() == 1) row_servers.insert(*row_servers_i.begin());
    }

    // loop through cols
    for(size_t j = 0; j < N; ++j) {

      std::set<int> col_servers_j;

      for(size_t i = 0; i < M; ++i) {
        if(grid[i][j] == 1) col_servers_j.insert(i*N + j);
      }

      if(col_servers_j.size() == 1) col_servers.insert(*col_servers_j.begin());
    }

    std::set<int> intersection;
    std::set_intersection(row_servers.begin(), row_servers.end(), col_servers.begin(), col_servers.end(), std::inserter(intersection, intersection.begin()));

    return num_servers - intersection.size();
  }
};