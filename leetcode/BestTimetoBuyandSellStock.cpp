#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0;
        int left = 0; // day we buy
        int right = 1; // day we sell

        while (right < prices.size()){
            if (prices[right] < prices[left]){
                left = right; // we find a better buy price
            }else if (prices[right] - prices[left] > maxProfit){
                maxProfit = prices[right] - prices[left];
            }
            right++;
        }
        return maxProfit;
    }
};