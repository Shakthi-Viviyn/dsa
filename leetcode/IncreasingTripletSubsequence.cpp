#include <vector>

using namespace std;

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        
        int first = numeric_limits<int>::max();
        int second = numeric_limits<int>::max();

        for (int i = 0; i < nums.size(); i++){

            if (nums[i] <= first){ // If found something smaller then first, set first to that num
                first = nums[i];
            }else if(nums[i] <= second){// else if found something smaller then second, set second to that num
                second = nums[i];
            }else{ // else if found something that is not smaller than first and second then it must be larger then both, hence we found our thir number larger than both
                return true;
            }
        }
        // If we don't find a number larger than first and second then return false
        return false;
    }
};