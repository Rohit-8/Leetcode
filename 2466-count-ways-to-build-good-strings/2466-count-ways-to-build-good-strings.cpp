class Solution {
public:
    int mod = 1000000007;
    vector<long long> dp;
    long long res(int z, int o, long long target, vector<long long> &dp){
        if(target == 0)
            return 1ll;
        if(target < 0)
            return 0;
        if(dp[target] != -1)
            return dp[target];
        
        long long sum = 0;
        sum += (res(z, o, target - z, dp) + res(z, o, target - o, dp)) % mod;
        return dp[target] = (sum % mod);
    }
    
    int countGoodStrings(int low, int high, int zero, int one) {
        
        long long ans = 0;
        dp.resize(high + 5, -1);
        for(int i = low; i <= high; i++){
            ans +=(res(zero, one, i, dp) + mod)% mod;
        }
        
        return ans % mod;
    }
};