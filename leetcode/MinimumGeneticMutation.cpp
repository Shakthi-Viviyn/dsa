#include <unordered_set>
#include <queue>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {

        const int gene[4] = {'A', 'C', 'G', 'T'};
        unordered_set<string> bank_set;
        for (int i = 0; i < bank.size(); i++){
            bank_set.insert(bank[i]);
        }
        
        unordered_set<string> checked;
        queue<pair<string, int>> q;

        q.push({startGene, 0});

        while(!q.empty()){
            string currGene = q.front().first;
            int numMut = q.front().second;
            q.pop();

            if (currGene == endGene){
                return numMut;
            }

            if (checked.find(currGene) == checked.end()){

                checked.insert(currGene);
                numMut++;

                for (int i = 0; i < 8; i++){
                    for (int j = 0; j < 4; j++){

                        string newGene = currGene;
                        newGene[i] = gene[j];
                        if (checked.find(newGene) == checked.end() && bank_set.find(newGene) != bank_set.end()){
                            q.push({newGene, numMut});
                        }
                        
                    }
                }
            }
        }
        return -1;
    }
};