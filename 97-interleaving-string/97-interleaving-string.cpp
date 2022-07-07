class Solution {
public:
    int dp[101][101];
    bool res(string &s1,string &s2,string &s3,int i,int j){
        if(i==s1.length() and j==s2.length()){
            return true;
        }
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        bool res1 = false,res2=false;
        if(i<s1.length() and s1[i]==s3[i+j]){
            res1=res(s1,s2,s3,i+1,j);
        }
        
        if(j<s2.length() and s2[j]==s3[i+j]){
            res2=res(s1,s2,s3,i,j+1);
        }
        
        return dp[i][j] = res1||res2;
    }
    bool isInterleave(string s1, string s2, string s3) {
        
        memset(dp,-1,sizeof(dp));
        
        if(s3.length()!= s2.length()+s1.length())
            return false;
        
        return res(s1,s2,s3,0,0);
    }
};