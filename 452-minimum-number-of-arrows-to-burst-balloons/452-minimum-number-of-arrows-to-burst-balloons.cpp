class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& p) {
        sort(p.begin(), p.end());
        
        int ans = 1;
        int a = p[0][0], b =  p[0][1];
        for(auto x : p) {
            if(x[0] <= b) {
                a = max(a, x[0]);
                b = min(b, x[1]);
            }
            else{
                a = x[0], b = x[1];
                ans++;
            }
        }
        
        return ans;
    }
};