class Solution {
public:
    // vector<int> dp;
    int climbStairs(int n) {
        if(n <= 2) return n;
        int prev2 = 1, prev = 2, x;
        for(int i = 3; i <= n; i++){
            x = prev2 + prev;
            prev2 = prev;
            prev = x;
        }
        
        return prev;
    }
};