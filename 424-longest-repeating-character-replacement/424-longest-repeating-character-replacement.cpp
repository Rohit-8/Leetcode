class Solution {
public:
    int characterReplacement(string s, int k) {
        int low = 0 , high = 0 ;
        
        int n = s.size() ;
        
        unordered_map<char,int> mp ;
        
        int ans = 1 ;
        
        while(high<n)
        {
            mp[s[high]]++ ;
            
            char ch = 'A' ;
            int mx = mp['A'] ;
            
            int req = 0 ;
            
            int sum = 0 ;
            
            for(auto i : mp)
            {
                if(i.second>mx)
                {
                    mx = i.second ;
                    ch = i.first ;
                }
                
                sum = sum + i.second ;
            }
            
            req = sum - mx ;
            
            if(req<=k)
            {
                ans = max(ans,high-low+1) ;
                high++ ;
            }
            else
            {
                mp[s[low]]-- ;
                low++ ;
                mp[s[high]]-- ;
            }
        }
        
        return ans ;
    }
};