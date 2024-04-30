#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string commonPrefix = "";
        for (int i = 0; i < strs[0].length(); i++){
            char currChar = strs[0][i];
            bool charIsCommon = true;
            for(int j = 1; j < strs.size(); j++){
                if (strs[j][i] != currChar){
                    charIsCommon = false;
                }
            }
            if (charIsCommon){
                commonPrefix += currChar;
            }else{
                break;
            }
        }
        return commonPrefix;
        
    }
};