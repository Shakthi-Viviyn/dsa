#include <unordered_map>
#include <string>

using namespace std;

// Solution using Hash table
class Solution {
public:
    bool canConstruct(std::string ransomNote, std::string magazine) {
        unordered_map<char, int> charCount;
        

        for (int i = 0; i < magazine.size(); i++){
            charCount[magazine[i]] += 1;
        }
        for (int i = 0; i < ransomNote.size(); i++){
            if ((charCount[ransomNote[i]]) == 0){
                return false;
            }
            charCount[ransomNote[i]] -= 1;
        }
        return true;
    }
};

// Hyper optimized solution using array

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int charCount[26];
        
        for (int i = 0; i < magazine.size(); i++){
            charCount[magazine[i] - 'a'] += 1;
        }
        for (int i = 0; i < ransomNote.size(); i++){
            if ((charCount[ransomNote[i] - 'a']) == 0){
                return false;
            }
            charCount[ransomNote[i] - 'a'] -= 1;
        }
        return true;
    }
};