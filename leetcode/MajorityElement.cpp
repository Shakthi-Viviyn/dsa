#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int majorityElement(std::vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        int currNum = 0;
        int currNumCnt = 0;
        for (int i = 0; i < nums.size(); i++){
            if (currNumCnt > (nums.size() / 2)){
                return currNum;
            }
            if (currNum != nums[i]){
                currNum = nums[i];
                currNumCnt = 1;
            }else{
                currNumCnt++;
            }
        }
        return currNum;
    }
};