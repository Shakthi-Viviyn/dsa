#include <queue>
class Solution {
public:
    int reverse(int x) {

        queue<int> q;

        while(x != 0){
            int digit = x % 10;
            x = x / 10;
            q.push(digit);
        }

        int result = 0;
        while(!q.empty()){
            if (result <= (std::numeric_limits<int>::max() / 10) && result >= (std::numeric_limits<int>::min() / 10)){
                result = (result * 10) + q.front();
            }else{
                return 0;
            }
            q.pop();
        }

        return result;
    }
};