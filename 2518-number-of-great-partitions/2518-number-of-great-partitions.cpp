class Solution {
public:
    const long long mod = 1000000007;
    long long res(vector<int> &a, int n, int sum, int k, vector<vector<int>> &dp){
        if(sum >= k)
            return 0;
        if(n >= a.size()){
            return 1ll;
        }
        
        if(dp[n][sum] != -1){
            return dp[n][sum];
        }
        return dp[n][sum] = (res(a, n + 1, sum + a[n], k, dp) + res(a, n + 1, sum, k, dp)) % mod;
    }
    
    int countPartitions(vector<int>& nums, int k) {
        long long sum = 0, c = 1;
        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];
            c = (c * 2) % mod;
        }
        
        if(sum / 2 < k)
            return 0;
        vector<vector<int>> dp(nums.size() + 1, vector<int> (k + 1, -1));
        long long x = 2ll * res(nums, 0, 0, k, dp);
        
        cout << c << " " << x << endl;
        
        return (c - x + mod) % mod; 
    }
};