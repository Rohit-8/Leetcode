class Solution {
public:
    void setZeroes(vector<vector<int>>& mat) {
        
        bool f = false, f2 = false;
        int n = mat.size(), m = mat[0].size();
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++){
                if(mat[i][j] == 0){
                    if(i == 0) f2 = true;
                    else if(j == 0) f = true;
                    else mat[0][j] = mat[i][0] = 0;
                }
            }
        
        for(int i = n-1; i >= 0; i--)
            for(int j = m-1; j >= 0; j--){
                
                if(mat[0][j] == 0 or mat[i][0] == 0)
                    mat[i][j] = 0;
                if(j == 0 and f) mat[i][j] = 0;
                if(i == 0 and f2) mat[i][j] = 0;
            }
        
        if(f or f2) mat[0][0] = 0;
        return;
    }
};