#include <iostream>

class Solution {
public:
bool isPalindrome(int x) {

    if (x < 0){
        return false;
    }

    long x2 = x;
    long reverseX = 0;
    while(x2 != 0){
        int numToAdd = x2 % 10;

        std::cout << "x2:" << x2 << std::endl;

        reverseX *= 10;
        reverseX += numToAdd;
        

        x2 -= numToAdd;
        x2 /= 10;
    }

    std::cout << "reverse: " << reverseX << std::endl;

    if (reverseX == x){
        return true;
    }
    
    return false;
}
};