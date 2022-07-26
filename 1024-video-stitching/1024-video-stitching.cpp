class Solution {
public:
    
    vector<vector<int>> dp;
    int res(vector<vector<int>> &a, int t, int prev, int n){
        if(prev >= t) return 0;
        if(n >= a.size()) return 1000000000;
        
        if(dp[n][prev] != -1) return dp[n][prev];
        
        int l = res(a, t, prev, n+1);
        if(a[n][0] <= prev){
            l = min(1 + res(a, t, a[n][1], n+1), l);
        }
        
        return dp[n][prev] = l;
        
    }
    
    int videoStitching(vector<vector<int>>& a, int t) {
        sort(begin(a), end(a));
        
        dp.resize(101, vector<int> (105, -1));
        int ans = res(a, t, 0, 0);
        
        if(ans >= 1000000000) return -1;
        
        return ans;
    }
};