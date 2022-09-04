class Solution {
public:
    vector<vector<int>> dp;
    int res(vector<int> &a, int n, int sum){
        if(sum == 0) return 1;
        if(n < 0) return 0;
        
        if(dp[n][sum] != -1) return dp[n][sum];
        int f = res(a, n - 1, sum);
        if(a[n] <= sum) 
            f |= res(a, n -1, sum - a[n]);
        
        return dp[n][sum] = f;
    }
    bool canPartition(vector<int>& a) {
        int sum = 0;
        for(int i = 0; i < a.size(); i++)
            sum += a[i];
        if(sum % 2) return false;
        dp.resize(a.size() + 1, vector<int> (sum / 2 + 1, -1));
        
        return res(a, a.size() - 1, sum / 2);
    }
};