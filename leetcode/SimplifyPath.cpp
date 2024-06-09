#include <sstream>
#include <stack>
#include <string>

using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        
        stack<string> s;
        stringstream ss(path);
        string token;
    
        while (std::getline(ss, token, '/')){
            if (token == ".."){
                if (!s.empty()){
                    s.pop();
                }
            }else if(!(token.empty()) and token != "."){
                s.push(token);
            }
        }

        string simpPath = "";
        while(!s.empty()){
            simpPath = "/" + s.top() + simpPath;
            s.pop();
        }
        return simpPath.empty() ? "/" : simpPath;
    }  
};