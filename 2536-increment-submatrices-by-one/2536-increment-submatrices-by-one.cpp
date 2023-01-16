class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> mat(n, vector<int>(n, 0));
        for(auto q : queries){
            mat[q[0]][q[1]]++;
            if(q[2] + 1 < n and q[3] + 1 < n) 
                mat[q[2] + 1][q[3] + 1]++;
            
            if(q[3] + 1 < n) 
                mat[q[0]][q[3] + 1]--;
            if(q[2] + 1 < n) 
                mat[q[2] + 1][q[1]]--; 
        }
        
        for (int r = 1; r < n; r ++) {
            for (int c = 0; c < n; c ++) 
                mat[r][c] += mat[r - 1][c];
        }
        
        for (int r = 0; r < n; r ++) {
            for (int c = 1; c < n; c ++) 
                mat[r][c] += mat[r][c - 1];
        }
        return mat;
    }
};