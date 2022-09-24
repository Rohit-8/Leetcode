class Solution {
public:
    int maxtilescovered(int idx , int nc , string &s , int len , vector<int>& v , vector<vector<int>>& dp)
    {
        while(idx<s.size()&&s[idx]=='0')
        {
            idx++ ;
        }
        
        if(nc==0||idx>=s.size())
        {
            return 0 ;
        }
        
        if(dp[idx][nc]!=-1)
        {
            return dp[idx][nc] ;
        }
        
        int i ;
        
        int count = 0 ;
        
        int low = idx , high = min(idx+len-1,(int)s.size()-1) ;
        
        count = v[high] ;
        
        if(low-1>=0)
        {
            count = count - v[low-1] ;
        }
        
        int pick = count + maxtilescovered(idx+len,nc-1,s,len,v,dp) ;
        
        int notpick = maxtilescovered(idx+1,nc,s,len,v,dp) ;
        
        return dp[idx][nc] = max(pick,notpick) ;
    }
    
    int minimumWhiteTiles(string &s, int nc, int len) {
        int n = s.size() ;
        
        int i ;
        
        vector<int> v(n,0) ;
        
        for(i=0;i<s.size();i++)
        {
            if(s[i]=='1')
            {
                v[i]++ ;
            }
        }
        
        for(i=1;i<v.size();i++)
        {
            v[i] = v[i] + v[i-1] ;
        }
        
        vector<vector<int>> dp(s.size()+1,vector<int>(nc+1,-1)) ;
        
        int curr = maxtilescovered(0,nc,s,len,v,dp) ;
        
        int count = 0 ;
        
        for(i=0;i<s.size();i++)
        {
            if(s[i]=='0')
            {
                count++ ;
            }
        }
        
        return s.size() - (count+curr) ;
    }
};