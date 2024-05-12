#include <unordered_map>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    bool makeEqual(std::vector<string>& words) {

        std::unordered_map<char, int> letterMap;

        for (int i = 0; i < words.size(); i++){
            for (int j = 0; j < words[i].length(); j++){
                letterMap[words[i][j]] += 1;
            }
        }
        for (int i = 0; i < 26; i++){
            if (letterMap['a' + i] % words.size() != 0){
                return false;
            }
        }
        return true;
    }
};