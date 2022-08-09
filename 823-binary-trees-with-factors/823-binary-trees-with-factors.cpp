class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        
        sort(arr.begin(),arr.end());
        int n=arr.size();
        int mod=1e9+7;
        map<int,int>dp;
        
        int ans=1;  
        dp[arr[0]]=1;
        
        for(int i=1;i<n;i++){
            dp[arr[i]]=1;
                for(int j=0;j<i;j++){
                    if(arr[i]%arr[j]==0 && dp.find(arr[i]/arr[j])!=dp.end())
                        dp[arr[i]]=((long int)dp[arr[i]]+(long int)dp[arr[j]]*  (long int)dp[arr[i]/arr[j]]) % mod;
                }
            
            ans=((long int)ans+(long int)dp[arr[i]])%mod;
        }
        return ans;
	}
};