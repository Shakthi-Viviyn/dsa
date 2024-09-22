#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    string reverseWords(string s) {

        stack<char> stk;
        string reversed;
        for (int i = s.length() - 1; i >= 0; i--){
            if (s[i] == ' '){
                if (!stk.empty()){
                    while(!stk.empty()){
                        reversed.push_back(stk.top());
                        stk.pop();
                    }
                    reversed.push_back(' ');
                }
                continue;
            }
            stk.push(s[i]);
        }
        if (!stk.empty()){
            while(!stk.empty()){
                reversed.push_back(stk.top());
                stk.pop();
            }
        }else{
            reversed.pop_back();
        }

        return reversed;
    }
};