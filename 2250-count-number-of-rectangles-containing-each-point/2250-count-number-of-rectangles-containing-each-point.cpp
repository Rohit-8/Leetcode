class Solution {
public:
    vector<int> countRectangles(vector<vector<int>>& rectangles, vector<vector<int>>& points) {
        vector<int> ans;
        vector<vector<int>> dp(101);
        for(int i = 0 ; i < rectangles.size(); i++)
        {
            dp[rectangles[i][1]].push_back(rectangles[i][0]);
        }
        for(int i = 0 ; i < 101; i++)
        {
            sort(dp[i].begin(), dp[i].end());
        }
        for(int i = 0 ; i < points.size(); i++)
        {
            int count = 0;
            int x = points[i][0];
            int y = points[i][1];
            for(int j = y; j < 101; j++)
            {
                int temp = lower_bound(dp[j].begin(), dp[j].end(), x) - dp[j].begin();
                count += dp[j].size() - temp;
            }
            ans.push_back(count);
        }
        
        return ans;
    }
};