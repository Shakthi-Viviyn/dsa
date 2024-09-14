#include <string>

using namespace std;

class Solution {
public:
    bool isAnagram(std::string s, std::string t) {
        
        if (s.length() != t.length()) return false;

        int charCount[26] = {0};

        for (int i = 0; i < s.length(); i++){
            charCount[s[i] - 'a']++;
        }

        for (int i = 0; i < t.length(); i++){
            int index = t[i] - 'a';
            if (charCount[index] == 0){
                return false;
            }
            charCount[index]--;
        }
        
        for (int i = 0; i < 26; i++){
            if (charCount[i] != 0){
                return false;
            }
        }
        return true;
    }
};