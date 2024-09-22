#include <string>

using namespace std;
class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        
        int i = 0;
        int j = 0;
        string merged;

        while(i < word1.length() || j < word2.length()){
            if (i < word1.length()){
                merged.push_back(word1[i]);
                i++;
            }
            if (j < word2.length()){
                merged.push_back(word2[j]);
                j++;
            }
        }
        return merged;
    }
};