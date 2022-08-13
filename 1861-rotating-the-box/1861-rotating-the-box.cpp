class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& a) {
        int n = a.size(), m = a[0].size();
        
        for(int i = 0; i < n; i++){
            int k = m - 1;
            for(int j = m -1; j >= 0; j--){
                if(a[i][j] == '*') k = j - 1;
                if(a[i][j] == '#'){
                    a[i][j] = '.';
                    a[i][k] = '#';
                    k--;
                }
            }
        }
        
        vector<vector<char>> ans;
        for(int i = 0; i < m; i++){
            vector<char> v;
            for(int j = n-1; j >= 0; j--){
                v.push_back(a[j][i]);
            }
            ans.push_back(v);
        }
        
        return ans;
    }
};