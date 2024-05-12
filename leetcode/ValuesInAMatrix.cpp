#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int numRows = grid.size();
        int numCols = grid[0].size();

        vector<vector<int>> maxLocal;

        for (int i = 1; i < numRows - 1; i++){
            maxLocal.push_back({});
            for (int j = 1; j < numCols - 1; j++){

                int maxVal = 0;
                for (int local_i = i - 1; local_i <= i + 1; local_i++){
                    for (int local_j = j - 1; local_j <= j + 1; local_j++){
                        if (grid[local_i][local_j] > maxVal){
                            maxVal = grid[local_i][local_j];
                        }
                    }
                }
                
                maxLocal[i - 1].push_back(maxVal);
            }
        }

        return maxLocal;
    }
};