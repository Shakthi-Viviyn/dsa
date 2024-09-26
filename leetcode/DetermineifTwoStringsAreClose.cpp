#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool closeStrings(string word1, string word2) {

        if (word1.size() != word2.size()) return false;

        unordered_set<char> s1;
        unordered_set<char> s2;

        vector<int> count1(26,0);
        vector<int> count2(26,0);

        for(int i = 0; i < word1.length(); i++){
            s1.insert(word1[i]);
            count1[word1[i] - 'a'] += 1;
        }
        for(int i = 0; i < word2.length(); i++){
            s2.insert(word2[i]);
            count2[word2[i] - 'a'] += 1;
        }
        if (s1 != s2) return false;

        sort(count1.begin(), count1.end());
        sort(count2.begin(), count2.end());

        if (count1 != count2) return false;

        return true;
    }
};