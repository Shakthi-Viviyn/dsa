#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int total = 0;
        for (int i = 0; i < nums.size(); i++){
            std::unordered_set<int> s;
            int distinctCount = 0;
            for(int j = i; j < nums.size(); j++){
                if (s.find(nums[j]) == s.end()){
                    s.insert(nums[j]);
                    distinctCount++;
                }
                total += (distinctCount * distinctCount);
            }
        }
        return total;
    }
};