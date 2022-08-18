class Solution {
public:
    int longestStrChain(vector<string>& a) {
        map<string, int> m;
        int n = a.size();
        
        sort(begin(a), end(a), [](string &x, string &y){
            return x.size() < y.size();
        });
        
        int ans = 1;
        for(int i = 0; i < n; i++){
            int r = a[i].size();
            
            m[a[i]] = 1;
            for(int j = 0; j < r; j++){
                string x = a[i].substr(0, j) + a[i].substr(j+1);
                
                if(m[x] > 0){
                    // cout<<x + k + y<<" ";
                    m[a[i]] = max(m[a[i]], 1 + m[x]);
                }
            }
            
            ans = max({ans, m[a[i]]});
        }
        
        return ans;
    }
};