class Solution {
public:
    int fib(int n) {
        if (n == 0) return 0;
        if (n == 1) return 1; 
        int a1 = 0;
        int a2 = 1;
        for (int i = 0 ; i <=  n - 2; i++){
            int tmp = a1 + a2;
            a1 = a2;
            a2 = tmp;
        }
        return a2;
    }
};
