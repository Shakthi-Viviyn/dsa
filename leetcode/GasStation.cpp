class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        
        int startIndex = 0;
        int currGas = 0;
        int netGas = 0;
        for (int i = 0; i < gas.size(); i++){
            netGas += gas[i] - cost[i];
            
            currGas += gas[i] - cost[i];
            if (currGas < 0){
                startIndex = i + 1;
                currGas = 0;
            }
        }
        if (netGas >= 0){
            return startIndex;
        }
        return -1;
    }
};