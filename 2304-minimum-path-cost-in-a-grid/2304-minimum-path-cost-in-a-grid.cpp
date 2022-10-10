class Solution {
public:
    map<pair<int, int>, vector<pair<pair<int,int>, int>>> m;
    map<int, pair<int, int>> mp;
    int n ;
    int ans = INT_MAX;
    vector<vector<int>> v;
    vector<vector<int>> dp;
    int res(int i, int j){
        if(i >= n - 1){
            return v[i][j];
        }
        if(dp[i][j] != -1) return dp[i][j];
        cout<<i<<" "<<j<<" "<<v[i][j]<<endl;
        int sum = INT_MAX;
        for(auto x: m[{i, j}]){
            sum = min(sum, v[i][j] + x.second + res(x.first.first, x.first.second));
        }
        return dp[i][j] = sum;
    }
    
    int minPathCost(vector<vector<int>>& a, vector<vector<int>>& c) {
        n = a.size();
        v = a;
        dp.resize(n + 1, vector<int> (a[0].size() + 1, - 1));
        // m = a[0].size();
        for(int i = 0; i < a.size(); i++){
            for(int j = 0; j < a[0].size(); j++){
                mp[a[i][j]] = {i, j};
            }
        }
//         for(int i = 0; i < n * a[0].size(); i++){
//             cout<<mp[i].first<<" "<<mp[i].second<<endl;
//         }
        for(int i = 0; i < c.size(); i++){
            for(int j = 0; j < c[i].size(); j++){
                m[mp[i]].push_back({{mp[i].first + 1, j}, c[i][j]});
            }
        }
        
        // for(int i = 0; i < n; i++){
        //     for(int j = 0; j < a[i].size(); j++){
        //         for(auto x: m[{i, j}]){
        //             cout<<x.first.first<<" "<<x.first.second<<" "<<x.second<<endl;
        //         }
        //         cout<<" f "<<endl;
        //     }
        // }
        
        for(int i = 0; i < a[0].size(); i++){
            ans = min(ans, res(0, i));
        }
        
        return ans;
    }
};