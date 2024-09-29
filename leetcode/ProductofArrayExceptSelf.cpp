#include <vector>

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {

        vector<int> res(nums.size(), 0);

        res[0] = 1;
        // Do the left pass and put the value of left products in result array
        for (int i = 1; i < res.size(); i++){
            res[i] = res[i - 1] * nums[i - 1];
        }

        // Variable to track right products up until current value of i
        int currProd = 1;

        // Calculate the rightProduct and multiply it directly to the left product value in res array
        for (int i = res.size() - 2; i >= 0; i--){
            currProd *= nums[i + 1];
            res[i] *= currProd;
        }

        return res;
    }
};