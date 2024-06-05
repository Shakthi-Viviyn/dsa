class Solution {
public:
    int climbStairs(int n){
        int* memo = new int[n + 1]();
        memo[0] = 1;
        int i = 0;
        while(i <= n){
            if ((i + 1) <= n) {
                memo[i + 1] += memo[i];
            }
            if ((i + 2) <= n) {
                memo[i + 2] += memo[i];
            }
            i++;
        }
        return memo[n];
    }
};