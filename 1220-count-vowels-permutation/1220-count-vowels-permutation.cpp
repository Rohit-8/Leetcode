class Solution {
public:
    int mod = 1e9+7;
    int count(int n, int last, vector<vector<int>> &dp)
    {
        if(n <= 0) return 1;
        
        if(dp[n][last] != -1) return dp[n][last];
        
        int res=0;
        
        if(last == 'a')
            res = (res%mod + count(n-1, 'e', dp)%mod)%mod;
        
        else if(last == 'e'){
            res = (res%mod + count(n-1, 'a', dp)%mod)%mod;
            res = (res%mod + count(n-1, 'i', dp)%mod)%mod ;
        }
        else if(last == 'i'){
            res = (res%mod + count(n-1, 'a', dp)%mod)%mod;
            res = (res%mod + count(n-1, 'e', dp)%mod)%mod;
            res = (res%mod + count(n-1, 'u', dp)%mod)%mod;
            res = (res%mod + count(n-1, 'o', dp)%mod)%mod;
        }
        else if(last == 'o'){
            res = (res%mod + count(n-1, 'i', dp)%mod)%mod;
            res = (res%mod + count(n-1, 'u', dp)%mod)%mod;
        }
        else if(last == 'u')
            res = (res%mod + count(n-1, 'a', dp)%mod)%mod;
        
        return dp[n][last] = res%mod;
    }
    
    int countVowelPermutation(int n) {
        
        vector<vector<int>> dp(n, vector<int> (150, -1));
        char vowels[] = {'a', 'e', 'i', 'o', 'u'};
        int res = 0;
        
        for(int i = 0; i < 5; i++)
            res = (res%mod + count(n-1, vowels[i], dp)%mod)%mod;
        
        return res;
    }
};