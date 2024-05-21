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

// Optimized sliding window solution using hash-set

#include <unordered_set>

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0, right = 0;
        std::unordered_set<char> charSet;
        int maxSize = 0;
        int i = 0;
        while(i < s.length()){
            char currChar = s[i];
            if (charSet.find(currChar) == charSet.end()){
                charSet.insert(currChar);
                right++;
            }else{
                while(s[left] != currChar){
                    charSet.erase(s[left]);
                    left++;
                }
                left++;
                right++;
            }
            i++;
            maxSize = maxSize > right-left ? maxSize : right-left;
        }
        return maxSize;
    }
};