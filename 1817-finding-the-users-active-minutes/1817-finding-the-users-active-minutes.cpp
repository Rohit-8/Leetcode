class Solution {
public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>>& a, int n) {
        unordered_map<int, set<int>> m;
        for(int i = 0; i < a.size(); i++){
            m[a[i][0]].insert(a[i][1]);
        }
        map<int, int> mp;
        for(auto x: m){
            mp[(int)(x.second.size())]++;
        }
        
        vector<int> ans;
        for(int i = 1; i <= n; i++){
            if(mp.count(i))
                ans.push_back(mp[i]);
            else ans.push_back(0);
        }
        
        return ans;
    }
};