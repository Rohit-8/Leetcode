class Solution {
public:
    int mod = 1000000007;
    int countHousePlacements(int n) {
        long long prev = 1, p = 1;
        for(int i = 2; i <= n + 1; i++){
            long x = (p + prev) % mod;
            prev = p;
            p = x;
        }
        
        return 1ll * (p * p) % mod;
    }
};