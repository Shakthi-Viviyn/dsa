#include <stack>
#include <string>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        std::stack<char> charStack;
        for (int i = 0; i < s.length(); i++){
            char curr = s[i];
            if (curr == ')' || curr == '}' || curr == ']'){

                if (charStack.empty()){
                    return false;
                }

                char recentBracket = charStack.top();
                charStack.pop();

                if (getClosedBracket(recentBracket) != curr){
                    return false;
                }
            }else{
                charStack.push(curr);
            }
        }

        if (charStack.empty()){
            return true;
        }else{
            return false;
        }
    }

    char getClosedBracket(char openBracket){
        switch(openBracket){
            case '(':
                return ')';
            case '{':
                return '}';
            case '[':
                return ']';
            default:
                return '\0';
            
        }
    }
};