#include <string>

using namespace std;

class Solution {
public:
    int compareVersion(string version1, string version2) {
        int p1 = 0;
        int p2 = 0;
        while(p1 < version1.length() && p2 < version2.length()){
            int num1 = 0;
            while(version1[p1] != '.' && p1 < version1.length()){
                num1 = (num1 * 10) + (version1[p1] - '0');
                p1++;
            }
            int num2 = 0;
            while(version2[p2] != '.' && p2 < version2.length()){
                num2 = (num2 * 10) + (version2[p2] - '0');
                p2++;
            }

            if (num1 < num2){ 
                return -1;
            }else if(num1 > num2){
                return 1;
            }

            p1++;
            p2++;
        }

        while (p1 < version1.length()){
            int num1 = 0;
            while(version1[p1] != '.' && p1 < version1.length()){
                num1 = (num1 * 10) + (version1[p1] - '0');
                p1++;
            }
            if (num1 > 0){
                return 1;
            }
            p1++;
        }
        while (p2 < version2.length()){
            int num2 = 0;
            while(version2[p2] != '.' && p2 < version2.length()){
                num2 = (num2 * 10) + (version2[p2] - '0');
                p2++;
            }
            if (num2 > 0){
                return -1;
            }
            p2++;
        }

        return 0;
    }
};