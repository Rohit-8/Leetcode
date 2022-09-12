class Solution {
public:
    int n;
    vector<vector<int>> dp;
    bool res(vector<int> &a, int sum, int i){
        if(i < 0) return false;
        if(sum == 0) return true;
        
        if(dp[i][sum] != -1) return dp[i][sum];
        
        bool f = res(a, sum, i - 1);
        if(sum - a[i] >= 0)
            f |= res(a, sum - a[i], i - 1);
        
        return dp[i][sum] = f;
    }
    
    bool canPartition(vector<int>& a) {
        int sum = 0;
        n = a.size();
        for(int i = 0; i < n; i++){
            sum += a[i];
        }
        if(sum % 2) return false;
        dp.resize(n + 1, vector<int> (sum / 2 + 1, - 1));
        return res(a, sum / 2, n - 1);
    }
};