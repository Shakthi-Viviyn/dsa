#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    long long maximumHappinessSum(std::vector<int>& happiness, int k) {
        std::sort(happiness.begin(), happiness.end());

        long long totalHappiness = 0;
        int turns = 0;
        while(k > 0){
            int currMax = happiness[happiness.size()-1] - turns;
            if (currMax > 0){
                totalHappiness += currMax;
            }else{
                break;
            }
            turns++;
            happiness.pop_back();
            k--;
        }
        return totalHappiness;
    }
};