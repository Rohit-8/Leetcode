class Solution {
public:
    int solve(int i , int j , vector<vector<int>>&dp , vector<int>& arr)
    {
        if(i >= j)
        {
            return 0;
        }
        if(dp[i][j] != -1)
            return dp[i][j];
        int mx = INT_MAX;
        vector<int> left_max(j - i + 1 , 0) , right_max(j - i + 1 , 0);
        left_max[0] = arr[i];
        for(int k = i + 1; k <= j ; k++)
            left_max[k - i] = max(left_max[k - i  - 1] , arr[k]);
        
        right_max[j - i] = arr[j];
        for(int k = j - 1; k>= i; k--)
        {
            right_max[k - i] = max(right_max[k - i + 1], arr[k]);
        }
        
        for(int k = i; k < j; k++)
        {
            mx = min(mx , solve(i , k , dp , arr) + solve(k + 1 , j , dp , arr) + left_max[k - i]*right_max[k + 1 - i]);
        }
        return dp[i][j] = mx;
    }
    
    int mctFromLeafValues(vector<int>& arr) {
     
        int n = arr.size();
        vector<vector<int>> dp(n + 1 , vector<int>(n + 1 , -1));
        int ans = solve(0 , n - 1 , dp , arr);
        return ans;
    }
};