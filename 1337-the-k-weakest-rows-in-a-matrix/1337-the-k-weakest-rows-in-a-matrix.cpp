class Solution {
public:
    
    static bool cmp(pair<int,int> &a, pair<int,int> &b){
        if(a.first == b.first) return a.second < b.second;
        return a.first < b.first;
    }
    
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<pair<int,int>> v;
        for(int i = 0; i < mat.size(); i++){
            int sum = 0;
            for(int j = 0; j < mat[i].size(); j++){
                if(mat[i][j] == 1) sum ++;
            }
            v.push_back({sum, i});
        }
        
        sort(v.begin(), v.end(), cmp);
        vector<int> ans;
        for(int i = 0;i < k; i++){
            ans.push_back(v[i].second);
        }
        
        return ans;
    }
};