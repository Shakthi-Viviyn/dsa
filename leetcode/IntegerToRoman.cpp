#include <unordered_set>
#include <string>

class Solution {
public:

    std::string intToRoman(int num) {

        std::string result = "";
        std::unordered_set<char> s;
    
        while (num != 0){

            if (num >= 1000){
                num -= 1000;
                result.append("M");

            }else if(num >= 900){
                num -= 900;
                result.append("CM");

            }else if(num >= 500 && (s.find('D') == s.end())){
                num -= 500;
                result.append("D");
                s.insert('D');

            }else if(num >= 400){
                num -= 400;
                result.append("CD");

            }else if(num >= 100){
                num -= 100;
                result.append("C");

            }else if(num >= 90){
                num -= 90;
                result.append("XC");

            }else if(num >= 50 && (s.find('L') == s.end())){
                num -= 50;
                result.append("L");
                s.insert('L');

            }else if(num >= 40){
                num -= 40;
                result.append("XL");

            }else if(num >= 10){
                num -= 10;
                result.append("X");

            }else if(num >= 9){
                num -= 9;
                result.append("IX");

            }else if(num >= 5 && (s.find('V') == s.end())){
                num -= 5;
                result.append("V");
                s.insert('V');

            }else if(num >= 4){
                num -= 4;
                result.append("IV");

            }else{
                num -= 1;
                result.append("I");
                
            }
        }
        return result;
    }
};