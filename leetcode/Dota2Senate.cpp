#include <string>
#include <queue>

using namespace std;

class Solution {
public:
    string predictPartyVictory(string senate) {
        int n = senate.length();
        queue<int> radiant, dire;
        
        for (int i = 0; i < n; ++i) {
            if (senate[i] == 'R'){
                radiant.push(i);
            }else{
                dire.push(i);
            }
        }
        
        while (!radiant.empty() && !dire.empty()) {
            int r_index = radiant.front();
            int d_index = dire.front();
            radiant.pop();
            dire.pop();
            
            if (r_index < d_index){
                radiant.push(n + r_index);
            }else{
                dire.push(n + r_index);
            }
        }
        
        return radiant.empty() ? "Dire" : "Radiant";
    }
};