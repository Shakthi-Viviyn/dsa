#include <vector>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int i = 2;
        vector<int> mem;
        if (nums.size() >= 1){
            mem.push_back(nums[0]);
        }
        if (nums.size() >= 2){
            if (mem[0] > nums[1]){
                mem.push_back(mem[0]);
            }else{
                mem.push_back(nums[1]);
            }
        }

        while (i < nums.size()){
            if (mem[i-2] + nums[i] > mem[i-1]){
                mem.push_back(mem[i-2] + nums[i]);
            }else{
                mem.push_back(mem[i-1]);
            }
            i++;
        }

        return *(mem.end() - 1);
    }
};