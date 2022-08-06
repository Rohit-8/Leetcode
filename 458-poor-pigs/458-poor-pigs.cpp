class Solution {
public:
    int poorPigs(int bc, int mt, int mn) {
        
        int x = mn / mt;
        x ++;
        int ans = 0;
        while(pow(x, ans) < bc)
            ans ++;
        
        return ans;
    }
};