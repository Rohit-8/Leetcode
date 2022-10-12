class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& a) {
        sort(a.begin(), a.end());
        int ans = 0;
        
        for(int i = 1; i < a.size(); i++){
            ans = max(ans, a[i][0] - a[i - 1][0]);
        }
        
        return ans;
    }
};