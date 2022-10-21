class Solution {
public:
    int equalPairs(vector<vector<int>>& a) {
        map<vector<int>, int> m1, m2;
        
        for(int i = 0; i < a.size(); i++){
            vector<int> v;
            for(int j = 0; j < a[i].size(); j++){
                v.push_back(a[i][j]);
            }
            m1[v]++;
        }
        int ans = 0;
        for(int i = 0; i < a[0].size(); i++){
            vector<int> v;
            for(int j = 0; j < a.size(); j++){
                v.push_back(a[j][i]);
            }
            m2[v]++;
        }
        for(auto x: m1){
            if(m2[x.first])
                ans += x.second * m2[x.first];
        }
        
        return ans;
    }
};