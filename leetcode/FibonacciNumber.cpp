class Solution {
public:
    int fib(int n) {
        if (n == 0) return 0;
        if (n == 1 || n == 2) return 1;
        int* fib_arr = new int[n+1];
        fib_arr[1] = 1;
        fib_arr[2] = 1;
        for (int i = 3; i <= n; i++){
            fib_arr[i] = fib_arr[i-1] + fib_arr[i-2];
        }
        return fib_arr[n];
    }
};