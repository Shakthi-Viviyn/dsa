#include <vector>

using namespace std;

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        
        int start = 0;
        int end = 0;
        int numZeroes = 0;
        int maxLen = 0;
        while(end < nums.size()){

            if (nums[end] == 0){
                numZeroes++;
            }

            while(numZeroes > 1){
                if (nums[start] == 0){
                    numZeroes--;
                }
                start++;
            }
            
            maxLen = max(maxLen, end - start);
            
            end++;
        }

        return maxLen;
    }
};