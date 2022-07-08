class Solution {
public:
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        long long int dp[m+1][target+1][n+1];
        for(int i=0;i<=m;i++)
        {
            for(int j=0;j<=target;j++)
            {
                for(int k=0;k<=n;k++)
                {
                    dp[i][j][k]=(i || j?INT_MAX:0);
                }
            }
        }
        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=target;j++)
            {
                for(int k=1;k<=n;k++)
                {
                    if(!houses[i-1])
                    {
                        for(int l=1;l<=n;l++)
                        {
                            if(k==l) dp[i][j][k]=min(dp[i][j][k],dp[i-1][j][l]+cost[i-1][k-1]);
                            else dp[i][j][k]=min(dp[i][j][k],dp[i-1][j-1][l]+cost[i-1][k-1]);
                        }
                    }
                    else if(k==houses[i-1])
                    {
                        for(int l=1;l<=n;l++)
                        {
                            if(k==l) dp[i][j][k]=min(dp[i][j][k],dp[i-1][j][l]);
                            else dp[i][j][k]=min(dp[i][j][k],dp[i-1][j-1][l]);
                        } 
                    }   
                }
            }
        }
        long long int ans=INT_MAX;
        for(int k=1;k<=n;k++)
        {
            ans=min(ans,dp[m][target][k]);
        }
        return (ans==INT_MAX?-1:ans); 
    }
};