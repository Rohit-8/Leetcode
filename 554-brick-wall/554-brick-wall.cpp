class Solution {
public:
    int leastBricks(vector<vector<int>>& a) {
        map<int, int> m;
        for(int i = 0; i < a.size(); i++){
            int c = 0;
            for(int j = 0; j < a[i].size() - 1; j++){
                c += a[i][j];
                m[c]++;
            }
        }
        int ans = 0;
        for(auto x: m){
            ans = max(ans, x.second);
        }
        
        return a.size() - ans;
    }
};