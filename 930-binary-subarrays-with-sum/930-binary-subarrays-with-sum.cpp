class Solution {
public:
    int numSubarraysWithSum(vector<int>& v, int k) {
        int n = v.size() ;
        int ans = 0 , prev = 0 ;
        for(int i=1;i<n;i++)
            v[i] = v[i] + v[i-1] ;
        
        for(int i=0;i<n;i++){
            
            int lower = lower_bound(v.begin()+i,v.end(),prev+k) - v.begin() ;
            int upper = upper_bound(v.begin()+i,v.end(),prev+k) - v.begin() ;
            
            if(lower==n) break ;
            ans = ans + upper - lower ;
            prev = v[i] ;
        }
        
        return ans ;
    }
};