#include <vector>

using namespace std;

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        
        int start = 0;
        int end = 0;
        int maxOnes = 0;
        int numZeroes = 0;
        while(end < nums.size()){
            
            if (nums[end] == 0){
                numZeroes++;
            }

            while(numZeroes > k){
                if (nums[start] == 0){
                    numZeroes--;
                }
                start++;
            }   

            maxOnes = max(maxOnes, end - start + 1);

            end++;
        }
        return maxOnes;
    }
};