class Solution {
public:
    int numSubarraysWithSum(vector<int>& v, int k) {
        int i ;
        
        int n = v.size() ;
        
        int ans = 0 , prev = 0 ;
        
        for(i=1;i<n;i++)
        {
            v[i] = v[i] + v[i-1] ;
        }
        
        for(i=0;i<n;i++)
        {
            int curr = prev + k ;
            
            int lower = lower_bound(v.begin()+i,v.end(),curr) - 
                                        v.begin() ;
            int upper = upper_bound(v.begin()+i,v.end(),curr) - 
                                        v.begin() ;
            
            if(lower==n)
            {
                break ;
            }
            else
            {
                ans = ans + upper - lower ;
            }
            
            prev = v[i] ;
        }
        
        return ans ;
    }
};