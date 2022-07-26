class Solution {
public:
    
    int longestArithSeqLength(vector<int>& v) {
        int n=v.size();
        vector<vector<int>> dp(1001, vector<int>(n+1,1));
        int ans=0;
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
			
                int d = v[i]-v[j] + 500;
				dp[d][i] = dp[d][j]+1;
                ans = max(ans,dp[d][i]);
            }
        }
        return ans;
    }
};