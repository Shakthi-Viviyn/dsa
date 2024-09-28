class Solution {
public:
    int tribonacci(int n) {
        
        if (n == 0) return 0;
        if (n == 1) return 1;
        if (n == 2) return 1;

        int i = 3;
        int mem[4] = {0, 1, 1, 2};
        while (i <= n){
            mem[3] = mem[2] + mem[1] + mem[0];
            mem[0] = mem[1];
            mem[1] = mem[2];
            mem[2] = mem[3];
            i++;
        }
        return mem[3];
    }
};