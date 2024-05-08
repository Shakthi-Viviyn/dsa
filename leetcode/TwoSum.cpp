// O(N^2) algorithm slow

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

//Improvised O(N) algorithm using a hash map

#include <unordered_map>

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        std::unordered_map<int, int> s;
        vector<int> answer;

        for (int i = 0; i < nums.size(); i++){
            s[nums[i]] = i;
        }
        for (int i = 0; i < nums.size(); i++){
            int remVal = target - nums[i];
            if (s.find(remVal) != s.end() && i != s[remVal]){
                answer.push_back(i);
                answer.push_back(s[remVal]);
                return answer;
            }
        }
        return answer;
    }
};