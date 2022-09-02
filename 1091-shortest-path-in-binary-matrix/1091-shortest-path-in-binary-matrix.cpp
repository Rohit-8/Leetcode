class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& a) {
        int n = a.size(), m = a[0].size();
        if(a[0][0] == 1) return -1;
        
        queue<pair<int,int>> q;
        q.push({0,0});
        int ans = 0;
        // vector<vector<int>> vis;
        while(!q.empty()){
            ans++;
            
            int x = q.size();
            for(int k = 0; k < x; k++){
                int i = q.front().first;
                int j = q.front().second;
                q.pop();
                if(i == n-1 and j == m-1) return ans;
                
                if(i-1 >= 0 and a[i-1][j] == 0){
                    q.push({i-1, j});
                    a[i-1][j] = 1;
                }
                if(j-1 >= 0 and a[i][j-1] == 0){
                    q.push({i, j-1});
                    a[i][j-1] = 1;
                }
                if(i+1 < n and a[i+1][j] == 0){
                    q.push({i+1, j});
                    a[i+1][j] = 1;
                }
                if(j+1 < m and a[i][j+1] == 0){
                    q.push({i, j+1});
                    a[i][j+1] = 1;
                }
                if(i + 1 < n and j + 1 < m and a[i + 1][j + 1] == 0){
                    q.push({i + 1, j + 1});
                    a[i + 1][j + 1] = 1;
                }
                if(i + 1 < n and j - 1 >= 0 and a[i + 1][j - 1] == 0){
                    q.push({i + 1, j - 1});
                    a[i + 1][j - 1] = 1;
                }
                if(i - 1 >= 0 and j + 1 < m and a[i - 1][j + 1] == 0){
                    q.push({i - 1, j + 1});
                    a[i - 1][j + 1] = 1;
                }
                if(i - 1 >= 0 and j - 1 >= 0 and a[i - 1][j - 1] == 0){
                    q.push({i - 1, j - 1});
                    a[i - 1][j - 1] = 1;
                }
                
            }
        }
        
        return -1;
    }
};