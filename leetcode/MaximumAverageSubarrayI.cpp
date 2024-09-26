#include <vector>

using namespace std;

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {

        double sum = 0;
        for (int i = 0; i < k; i++){
            sum += nums[i]; // load the values for first window
        }

        double maxSum = sum;
        for (int i = k; i < nums.size(); i++){
            sum += nums[i] - nums[i - k]; // Slide the window
            maxSum = max(sum, maxSum); // Find the maximum sum
        }

        return (maxSum / k); // divide maximum sum by k to get max average
    }
};