#include <vector>

using namespace std;


// Solution 1 : Hold stock if prices going up and sell when prices going down
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // capture every up

        int left = 0;
        int right = 1;
        int profit = 0;
        while (right < prices.size()){
            if (prices[right] < prices[right - 1]){
                profit += prices[right - 1] - prices[left];
                left = right;
            }
            right++;
        }
        if (prices[right - 1] - prices[left] > 0){
            profit += prices[right - 1] - prices[left];
        }
        return profit;
    }
};

// Solution 2 : Sell every other day when prices went up (simpler but slower)

class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int profit = 0;
        for (int i = 1; i < prices.size(); i++){
            if (prices[i] > prices[i - 1]){
                profit += prices[i] - prices[i - 1];
            }
        }
        return profit;
    }
};