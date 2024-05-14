#include <vector>

using namespace std;

class Solution {
public:
    int getMaximumGold(vector<vector<int>>& grid) {
        int maxVal = 0;
        for (int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[i].size(); j++){
                if (grid[i][j] != 0){
                    maxVal = std::max({getMaxiumHelper(i,j, grid), maxVal});
                }
            }
        }
        return maxVal;
    }
    int getMaxiumHelper(int i, int j, vector<vector<int>>& grid){
        int currGold = grid[i][j];
        grid[i][j] = 0;
        if (currGold == 0){
            return 0;
        }

        int left = 0, right = 0, up = 0, down = 0;
        if ( i - 1 >= 0 && grid[i-1][j] != 0){
            left = getMaxiumHelper(i-1, j, grid);
        }
        if (i + 1 < grid.size() && grid[i+1][j] != 0){
            right = getMaxiumHelper(i + 1, j, grid);
        }
        if (j - 1 >= 0 && grid[i][j-1] != 0){
            up = getMaxiumHelper(i, j - 1, grid);
        }
        if (j + 1 < grid[i].size() && grid[i][j+1] != 0){
            down = getMaxiumHelper(i, j + 1, grid);
        }
        int greatest = std::max({left, right, up, down});
        grid[i][j] = currGold;

        return currGold + greatest;
    }
};