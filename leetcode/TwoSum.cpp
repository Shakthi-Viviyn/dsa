# include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> answer;
        for (int i = 0; i < nums.size(); i++){
            for (int j = 0; j < nums.size(); j++){
                if (nums[i] + nums[j] == target && i != j){
                    answer.push_back(i);
                    answer.push_back(j);
                    return answer;
                }
            }
        }
        return answer;
    }
};