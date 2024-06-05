#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {

        std::unordered_map<char, std::vector<char>> mapping = {
            {'2', {'a', 'b', 'c'}},
            {'3', {'d', 'e', 'f'}},
            {'4', {'g', 'h', 'i'}},
            {'5', {'j', 'k', 'l'}},
            {'6', {'m', 'n', 'o'}},
            {'7', {'p', 'q', 'r', 's'}},
            {'8', {'t', 'u', 'v'}},
            {'9', {'w', 'x', 'y', 'z'}}
        };
        vector<string> combinations;
        string s = "";
        if (digits != ""){
            findCombinations(s, digits, 0, combinations, mapping);
        }
        return combinations;
    }

    void findCombinations(string & s, string & digits, int i, vector<string> & combinations, std::unordered_map<char, std::vector<char>> & mapping){
      
        if (i >= digits.length()){
            combinations.push_back(s);
            return;
        }
      
        for (char letter : mapping[digits[i]]){
            s.push_back(letter);
            findCombinations(s, digits, i + 1, combinations, mapping);
            s.pop_back();
        }
    }
};