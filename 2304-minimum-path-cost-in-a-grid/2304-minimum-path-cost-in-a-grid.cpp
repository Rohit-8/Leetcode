class Solution {
public:
    map<pair<int, int>, vector<pair<pair<int,int>, int>>> m;
    map<int, pair<int, int>> mp;
    int n ;
    int ans = INT_MAX;
    // vector<vector<int>> v;
    vector<vector<int>> dp;
    
    int res(int i, int j, vector<vector<int>>& a){
        if(i >= n - 1){
            return a[i][j];
        }
        if(dp[i][j] != -1) return dp[i][j];
        
        int sum = INT_MAX;
        for(auto x: m[{i, j}]){
            sum = min(sum, a[i][j] + x.second + res(x.first.first, x.first.second, a));
        }
        return dp[i][j] = sum;
    }
    
    int minPathCost(vector<vector<int>>& a, vector<vector<int>>& c) {
        n = a.size();
        // v = a;
        dp.resize(n + 1, vector<int> (a[0].size() + 1, - 1));
        
        for(int i = 0; i < a.size(); i++){
            for(int j = 0; j < a[0].size(); j++){
                mp[a[i][j]] = {i, j};
            }
        }
        for(int i = 0; i < c.size(); i++){
            for(int j = 0; j < c[i].size(); j++){
                m[mp[i]].push_back({{mp[i].first + 1, j}, c[i][j]});
            }
        }
        
        for(int i = 0; i < a[0].size(); i++){
            ans = min(ans, res(0, i, a));
        }
        
        return ans;
    }
};