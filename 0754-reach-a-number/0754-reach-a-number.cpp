class Solution {
public:
    int reachNumber(int t) {
        t = abs(t);
        
        int ans = 0;
        while(t > 0)
            t -= (++ans);
            
        if(t % 2){
            return ans + 1 + ans % 2;
        }
        return ans;
    }
};