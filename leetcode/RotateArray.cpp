#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

// Simple approach using array reversal

class Solution {
public:
    void rotate(vector<int>& nums, int k) {

        if (k == 0) return;
        k = k % nums.size();

        std::reverse(nums.begin(), nums.end());
        std::reverse(nums.begin(), nums.begin()+k);
        std::reverse(nums.begin()+k, nums.end());
    }
};

// More complicated approach using cyclic replacement

class Solution {
public:
    void rotate(vector<int>& nums, int k) {

        if (k == 0) return;
        int count = nums.size();
        int totalPasses = std::gcd(count, k);

        int countPasses = 0;
        int startIndex = 0;
        while(countPasses < totalPasses){
            int i = startIndex;
            int currNum = nums[i];
            int numShiftsCurrPass = 0;
            while(numShiftsCurrPass <= count / totalPasses){
                int next = (i + k) % count;
                int temp = nums[next];
                nums[next] = currNum;
                currNum = temp;
                numShiftsCurrPass++;
                i = next;
            }
            countPasses++;
            startIndex++;
        }
    }
};

