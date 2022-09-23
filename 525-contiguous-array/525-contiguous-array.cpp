class Solution {
public:
    int findMaxLength(vector<int>& a) {
        map<int, int> m;
        int n = a.size();
        m[0] = -1;
        int c = 0, ans = 0;
        
        for(int i = 0; i < n; i++){
            if(a[i] == 0) c++;
            else c--;
            if(m.find(c) != m.end())
                ans = max(ans, i - m[c]);
            else m[c] = i;
        }
        
        return ans;
    }
};