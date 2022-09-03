class Solution {
public:
    
    int maximumRows(vector<vector<int>>& a, int c) {
        int n = a.size(), m = a[0].size();
        if(c >= m) return n;
        
        int ans = 0;
        string s = "";
        for(int i = 0; i < m; i++)
            s += '0';
        for(int i = 0; i < c; i++)
            s[i] = '1';
        
        for(int i = 0; i < n; i++){
            bool f = true;
            for(int j = 0; j < m; j++){

                if(s[j] == '0' and a[i][j] == 1){
                    f = false;
                    break;
                }
            }
            if(f) ans ++;
        }
        
        string w = s;
        next_permutation(s.begin(), s.end());
        while(1){
            if(w == s) break;
            int t = 0;
            
            for(int i = 0; i < n; i++){
                bool f = true;
                for(int j = 0; j < m; j++){
                    
                    if(s[j] == '0' and a[i][j] == 1){
                        f = false;
                        break;
                    }
                }
                if(f) t++;
            }
            ans = max(ans, t);
            next_permutation(s.begin(), s.end());
        }
        
        return ans;
    }
};