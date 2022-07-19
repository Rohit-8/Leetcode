class Solution {
public:
    vector<vector<int>> generate(int n) {
        
        vector<vector<int>> ans;
        
        for(int i = 1; i <= n; i++){
            vector<int> v;
            int x = 1;
            
            for(int j = 1; j <= i; j++){
                v.push_back(x);
                x = (x * (i-j)/j);
            }
            ans.push_back(v);
        }
        
        return ans;
    }
};