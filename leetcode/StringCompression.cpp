#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int compress(vector<char>& chars) {

        int runner = 0;
        int i = 0;
        while(runner < chars.size()){
            int count = 0;
            char currChar = chars[runner];
            while(runner < chars.size() && chars[runner] == currChar){
                count++;
                runner++;
            }

            chars[i] = currChar;
            i++;
            if (count > 1){
                string count_s = to_string(count);
                for (int j = 0; j < count_s.length(); j++){
                    chars[i] = count_s[j];
                    i++;
                }
            }
        }

        return i;
    }
};