#include <string>

using namespace std;

class Solution {
public:

    string longestPalindrome(string s) {

        int n = s.length();
        int start = 0;
        int maxLength = 0;

        for (int i = 0; i < s.length(); i++){

            // Symmetric case
            int left = i;
            int right = i;
            while(left > 0 && right < n - 1 && (s[left - 1] == s[right + 1])){
                left--;
                right++;
            }

            if (right - left + 1 >= maxLength){
                start = left;
                maxLength = right - left + 1;
            }

            // Mirror case
            left = i;
            right = i-1;
            while(left > 0 && right < n - 1 && (s[left - 1] == s[right + 1])){
                left--;
                right++;
            }

            if ((right - left + 1) > maxLength){
                start = left;
                maxLength = right - left + 1;
            }

        }

        return s.substr(start, maxLength);
    }
};