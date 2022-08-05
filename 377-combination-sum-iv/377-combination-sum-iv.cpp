int dp[200004];

class Solution {
public:
    
    
    int res(vector<int> &a, int n, int sum){
        if(sum <= 0) return dp[sum] = 1;
        
        if(dp[sum] != -1) return dp[sum];
        
        int s = 0;
        for(int i = 1; i <= n; i++){
            
            if(a[i-1] <= sum){
                s = s + res(a, n, sum-a[i-1]);
            }
            else break;
        }
        return dp[sum] = s;
    }
    
    int combinationSum4(vector<int>& a, int t) {
        sort(a.begin(), a.end());
        // dp.resize(t + 1, -1);
        memset(dp, -1, sizeof(dp));
        
        return res(a, a.size(), t);
    }
};