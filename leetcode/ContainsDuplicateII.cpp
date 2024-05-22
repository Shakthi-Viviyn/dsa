#include <unordered_set>
#include <vector>

class Solution {
public:
    bool containsNearbyDuplicate(std::vector<int>& nums, int k) {

        std::unordered_set<int> s;
        int i = 0;
        while(i <= k && i < nums.size()){
            if (s.find(nums[i]) != s.end()){
                return true;
            }
            s.insert(nums[i]);
            i++;
        }

        while(i < nums.size()){
            s.erase(nums[i - (k + 1)]);
            if (s.find(nums[i]) != s.end()){
                return true;
            }
            s.insert(nums[i]);
            i++;
        }
        return false;
    }
};