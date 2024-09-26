#include <string>

using namespace std;

class Solution {
public:
    int maxVowels(string s, int k) {

        int numVowels = 0;
        for (int i = 0; i < k; i++){
            if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u'){
                numVowels++;
            }
        }

        int maxNumVowels = numVowels;

        for (int i = k; i < s.length(); i++){
            if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u'){
                numVowels++;
            }
            if (s[i - k] == 'a' || s[i - k] == 'e' || s[i - k] == 'i' || s[i - k] == 'o' || s[i - k] == 'u'){
                numVowels--;
            }
            maxNumVowels = max(maxNumVowels, numVowels);
        }

        return maxNumVowels;
    }
};