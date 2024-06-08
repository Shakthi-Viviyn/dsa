#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> allCombinations;
        vector<int> currentComb;
        combineHelper(1, n, k, allCombinations, currentComb);
        return allCombinations;
    }

    void combineHelper(int currNum, int n, int k, vector<vector<int>> & sol, vector<int> & currComb){

        if (currComb.size() == k){
            sol.push_back(currComb);
            return;
        }
        for (int i = currNum; i <= n - k + currComb.size() + 1; i++){
            currComb.push_back(i);
            combineHelper(i + 1, n, k, sol, currComb);
            currComb.pop_back();
        }
    }
};