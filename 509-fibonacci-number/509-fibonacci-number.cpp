class Solution {
public:
    int fib(int n) {
        if(n <= 1) return n;
        
        int prev = 1, secp = 0;
        int ans = 1;
        for(int i = 2; i <= n; i++){
            ans = prev + secp;
            secp = prev;
            prev = ans;
        }
        return ans;
    }
};