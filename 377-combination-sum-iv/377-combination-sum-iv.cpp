int dp[200004];

class Solution {
public:

int Total_Ways(vector<int>& arr, int sum, int n)
{
    if(sum==0)
    {
        return dp[sum]=1;
    }
    
    if(dp[sum]!=-1)
    {
        return dp[sum];
    }
    
    int k, ways=0;
    for(k=1;k<=n;k++)
    {
        if(arr[k-1]<=sum)
        {
            ways=ways+Total_Ways(arr, sum-arr[k-1], n);
        }
        
    }
    
    return dp[sum]=ways;
}

int combinationSum4(vector<int>& nums, int target) {
    memset(dp, -1, sizeof dp);
    
    return Total_Ways(nums, target, nums.size());
    
}
};