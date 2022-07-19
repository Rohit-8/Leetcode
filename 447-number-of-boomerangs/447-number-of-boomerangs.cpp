class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& p) {
        int ans = 0;
        for (int i = 0; i < p.size(); i++) {
            unordered_map<int, int> m;
            for (int j = 0; j < p.size(); j++) {
                
                int l = p[j][1] - p[i][1];
                int r = p[j][0] - p[i][0];
                int x = l*l + r*r;
                if (m[x] > 0) {
                    ans += 2 * m[x];
                }
                m[x]++;
            }
        }
        
        return ans;
    }
};