#include <queue>
#include <unordered_map>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<std::string> findRelativeRanks(vector<int>& score) {
        std::priority_queue<std::pair<int, int>> rank;
        std::vector<std::string> result;
        std::unordered_map<int, int> scoreMap;

        for (int i = 0; i < score.size(); i++){
            rank.push({score[i],i});
        }

        int rankCount = 1;
        while(!rank.empty()){
            scoreMap[rank.top().second] = rankCount;
            rank.pop();
            rankCount++;
        }

        for (int i = 0; i < score.size(); i++){
            if (scoreMap[i] == 1){
                result.push_back("Gold Medal");
            }else if(scoreMap[i] == 2){
                result.push_back("Silver Medal");
            }else if(scoreMap[i] == 3){
                result.push_back("Bronze Medal");
            }else{
                result.push_back(std::to_string(scoreMap[i]));
            } 
        }

        return result;

    }

};