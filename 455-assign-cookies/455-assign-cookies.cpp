class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int ans = 0;
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        
        for(int i = 0, j = 0; i < g.size() and j < s.size(); i++){
            while(j < s.size() and g[i] > s[j])
                j++;
            if(j >= s.size()) break;
            ans++;
            j++;
        }
        
        return ans;
    }
};