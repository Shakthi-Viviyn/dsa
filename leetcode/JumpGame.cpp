#include <vector>

using namespace std;

class Solution {
public:
    bool canJump(std::vector<int>& nums) {
        
        int target = nums.size() - 1;
        for(int i = nums.size() - 1; i > -1; i--){
            if (target - i <= nums[i]){
                target = i;
            }
        }

        if (target == 0){
            return true;
        }
        return false;
    }
};