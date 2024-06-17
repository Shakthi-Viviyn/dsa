#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int currNumCount = 0;
        int swapIndex = 0;
        int currNum = 0;
        int i = 0;
        
        while (i < nums.size()){
            if (nums[i] != currNum){
                currNum = nums[i];
                currNumCount = 1;
            }else{
                currNumCount++;
            }

            if (currNumCount <= 2){
                nums[swapIndex] = nums[i];
                swapIndex++;
            }
            i++;
        }
        return swapIndex;
    }
};