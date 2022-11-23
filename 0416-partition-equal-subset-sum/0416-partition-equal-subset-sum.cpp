class Solution {
public:
    bool res(vector<int> &a, int n, int sum, vector<vector<int>> &dp){
        if(sum == 0)
            return true;
        if(n < 0)
            return false;
        if(dp[sum][n] != -1)
            return dp[sum][n];
        bool l = res(a, n - 1, sum, dp);
        if(sum >= a[n])
            l |= res(a, n - 1, sum - a[n], dp);
        return dp[sum][n] = l;
    }
    bool canPartition(vector<int>& a) {
        int sum = 0;
        for(int i = 0; i < a.size(); i++){
            sum += a[i];
        }
        if(sum % 2) return false;
        vector<vector<int>> dp(sum / 2 + 1, vector<int> (a.size() + 1, -1));
        
        return res(a, a.size() - 1, sum / 2, dp);
    }
};