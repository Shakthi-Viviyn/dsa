#include <string>

using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        
        int i = s.length() - 1;
        int size = 0;

        while(s[i] == ' '){
            i--;
        }
        while(i >= 0){
            if (s[i] == ' '){
               break;
            }
            size++;
            i--;
        }
        return size;

    }
};