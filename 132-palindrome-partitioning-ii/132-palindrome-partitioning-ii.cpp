class Solution {
public:
    
    bool ispal(string &s,int i, int j){
        
        while(i<j){
            if(s[i]!=s[j])
                return false;
            
            i++, j--;
        }
        return true;
    }
    
    
    int res(string &s,int i, int j, vector<vector<int>> &dp){
        if(i>=j) return 0;
        
        if(ispal(s,i,j)) return dp[i][j] = 0;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        int temp = INT_MAX;
        for(int k = i; k < j; k++){
    
            if(ispal(s, i, k)){
                
                int t = 1 + res(s,k+1,j, dp);
                temp = min(t,temp);
            }
        }
        
        return dp[i][j] = temp;
    }
    
    int minCut(string s) {
        vector<vector<int>> dp(s.size()+1, vector<int> (s.size() + 1, -1));
        
        return res(s,0,s.size()-1, dp);
    }
};