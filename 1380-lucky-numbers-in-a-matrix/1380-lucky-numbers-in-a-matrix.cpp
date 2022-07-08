class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& a) {
        
        int n = a.size();
        int m = a[0].size();
        
        vector<int> ans;
        for(int i = 0; i < n; i++){
            
            int mn = 10000000, k = 0;
            for(int j = 0; j < m; j++){ // in this loop i am finding the minimum element in row
                if(mn > a[i][j])
                mn = min(mn, a[i][j]), k = j;
            }
            int mx = 0, x = 0;
            for(int j = 0; j < n; j++){ // in this loop i am finding the max element in that column that has min ele. in row
                if(mx < a[j][k])
                    mx = max(a[j][k], mx), x = j;
            }
            
            if(mx == mn) // if both element matches then it is our ans
                ans.push_back(a[i][k]);
        }
        
        return ans;
        
    }
};