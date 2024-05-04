#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int currIndex = 0;
        for (int i = 0; i < nums.size(); i++){
            if (nums[i] != nums[currIndex]){
                nums[++currIndex] = nums[i];
            }
        }
        return currIndex + 1;
    }
};