#include <vector>

using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits){
        int carry, num;
        int i = digits.size() - 1;
        digits[i] += 1;
        while(i >= 0){
            if (carry != 0){
                digits[i] += carry;
                carry = 0;
            }
            if (digits[i] > 9){
                num = digits[i] % 10;
                carry = digits[i] / 10;
                digits[i] = num;
            }else{
                break;
            }
            i--;
        }
        if (carry > 0){
            digits.insert(digits.begin(), carry);
        }
        return digits;
    }
};