#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {

        if (s.length() != t.length()) return false;

        unordered_map<char, char> map;
        unordered_map<char, char> reverse_map;

        for (int i = 0; i < s.length(); i++){
            if (map.find(s[i]) == map.end()){
                map[s[i]] = t[i];
            }else{
                if (map[s[i]] != t[i]){
                    return false;
                }
            }
            if (reverse_map.find(t[i]) == map.end()){
                reverse_map[t[i]] = s[i];
            }else{
                if (reverse_map[t[i]] != s[i]){
                    return false;
                }
            }
        } 
        return true;
    }
};