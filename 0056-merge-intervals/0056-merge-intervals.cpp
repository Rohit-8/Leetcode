class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& a) {
        sort(a.begin(), a.end(), [](vector<int> &x, vector<int> &y){
            if(x[0] != y[0])
                return x[0] < y[0];
            return x[1] < y[1];
        });
        
        vector<vector<int>> ans;
        int x = a[0][0], y = a[0][1];
        for(int i = 1; i < a.size(); i++){
            if(y >= a[i][0]){
                y = max(a[i][1], y);
            }
            else{
                ans.push_back({x, y});
                x = a[i][0], y = a[i][1];
            }
        }
        ans.push_back({x, y});
        return ans;
    }
};