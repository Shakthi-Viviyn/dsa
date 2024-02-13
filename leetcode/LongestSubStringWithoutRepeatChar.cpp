#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        std::string subStr = "";
        int largestSize = 0;
        int i = 0;
        while(i < s.length()){
            char currChar = s[i];
            std::string::size_type pos = subStr.find(currChar);
            if (pos == std::string::npos){
                subStr.push_back(currChar);
                i++;
            }else{
                subStr = subStr.substr(subStr.find(currChar) + 1);
                continue;
            }
            largestSize = subStr.length() > largestSize ? subStr.length() : largestSize;
        }
        return largestSize;
    }
};