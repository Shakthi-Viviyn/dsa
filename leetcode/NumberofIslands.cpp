#include <vector>

using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int numIsland = 0;
        for (int i = 0; i < grid.size(); i++){
            for (int j = 0; j < grid[i].size(); j++){
                if (grid[i][j] == '1'){
                    numIsland += 1;
                    exploreIslands(i, j, grid);
                }
            }
        }
        return numIsland;
    }

    void exploreIslands(int i, int j, vector<vector<char>>& grid){
        if (i < 0 || i >= grid.size()){
            return;
        }
        if (j < 0 || j >= grid[0].size()){
            return;
        }
        if (grid[i][j] == '0'){
            return;
        }

        grid[i][j] = '0';
        exploreIslands(i - 1, j, grid);
        exploreIslands(i + 1, j, grid);
        exploreIslands(i, j - 1, grid);
        exploreIslands(i, j + 1, grid);
    }
};