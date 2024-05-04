#include <string>

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        int startIndex = 0;
        int i = 0;
        while(i < haystack.length()){
            if (haystack[i] == needle[0]){
                startIndex = i;
                bool allCharMatch = true;
                int j = 0;
                while(j < needle.length()){
                    if (i + j >= haystack.length()){
                        return -1;
                    }

                    if (haystack[i+j] != needle[j]){
                        allCharMatch = false;
                        break;
                    }
                    j++;
                }
                if (allCharMatch){
                    return startIndex;
                }
            }
            i++;
        }
        return -1;
    }
};