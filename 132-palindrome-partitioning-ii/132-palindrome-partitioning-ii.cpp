class Solution {
public:
    
    int dp[2002][2002];
    
     bool isPalindrome(string &s ,int i,int j){
        if(i>=j) return true;
        if(s[i]!=s[j]) return false;
        return isPalindrome(s,i+1,j-1);
    }
    
    int pal(string &s,int i,int j){
        if(i>=j) return 0;
        int &ans=dp[i][j];
        if(ans!=-1) return ans;
        if(isPalindrome(s,i,j)){
            return dp[i][j] = 0;
        }
        int minn=INT_MAX;
        for(int k=i;k<j;k++){
            if(isPalindrome(s, i, k)){
                int temp=pal(s,k+1,j)+1;
          
            minn=min(minn,temp);}
        }
        return dp[i][j] = minn;
    }
    
    int minCut(string &s) {
        memset(dp,-1,sizeof(dp));
        int ans=0;
        ans=pal(s,0,s.length()-1);
        return ans;
    }
};