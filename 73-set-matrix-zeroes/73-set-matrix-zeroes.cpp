class Solution {
public:
    void setZeroes(vector<vector<int>>& a) {
        int n = a.size();
        int m = a[0].size();
        
        int x = 0;
        if(a[0][0] == 0) x = 1;
        for(int i = 0; i < n; i++){
            
            for(int j = 0; j < m; j++){
                if(a[i][j] == 0 and i > 0){
                    a[0][j] = a[i][0] = 0;
                }
                else if(i == 0 and a[i][j] == 0) x = 1;
            }
        }
        int f = 1;
        if(x) f = 0;
        for(int i = n - 1; i >= f; i--){
            for(int j = m - 1; j >= 0; j --){
                if(a[0][j] == 0 or a[i][0] == 0)
                    a[i][j] = 0;
                if(i == 0 and x){
                    a[i][j] = 0;
                }
            }
        }
        
        
        return ;
    }
};