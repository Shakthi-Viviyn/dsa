#include <vector>

using namespace std;

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        
        // If no flowers need to be planted return true
        if (n == 0) return true;
        
        // If flowerbed has only 1 spot, handle that special case
        if (flowerbed.size() == 1 && flowerbed[0] == 0 && n == 1){
            return true;
        }

        // Handles edge case of zero index where there is no i - 1 index
        if (flowerbed[0] == 0 && flowerbed[1] == 0 ){ 
            flowerbed[0] = 1;
            n--;
        }
    
        for (int i = 1; i < flowerbed.size() - 1; i++){

            if (flowerbed[i - 1] == 0 && flowerbed[i] == 0 && flowerbed[i + 1] == 0){
                flowerbed[i] = 1;
                n--;
                if (n == 0) return true;
            }
        }

        // Handles edge case of last index where there is no i + 1 index
        if (flowerbed[flowerbed.size() - 1] == 0 && flowerbed[flowerbed.size() - 2] == 0){
            flowerbed[flowerbed.size() - 1] = 1;
            n--;
        }

        return n <= 0;
    }
};