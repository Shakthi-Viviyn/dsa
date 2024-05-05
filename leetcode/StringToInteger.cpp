#include <string>

using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        int i = 0;
        bool isPos = true;
        long num = 0;
        while(i < s.length() && s[i] == ' ') i++;

        if (s[i] == '-'){
            i++;
            isPos = false;
        }else if (s[i] == '+'){
            i++;
        }
        while(i < s.length() ){
            if (s[i] >= '0' && s[i] <= '9'){
                if (num > std::numeric_limits<int>::max()){
                    return std::numeric_limits<int>::max();
                }else if(num < std::numeric_limits<int>::min()){
                    return std::numeric_limits<int>::min();
                }
                int digit = s[i] - '0';
                if (!isPos) digit = -digit;
                num = (num * 10) + digit;
                i++;
            }else{
                break;
            }
        }
        if (num > std::numeric_limits<int>::max()){
            return std::numeric_limits<int>::max();
        }else if(num < std::numeric_limits<int>::min()){
            return std::numeric_limits<int>::min();
        }
        return num;
    }
};