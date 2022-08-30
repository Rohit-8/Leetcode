class Solution {
public:
    int orangesRotting(vector<vector<int>>& a) {
        int n = a.size(), m = a[0].size();
        // vector<vector<int>> vis(n + 1, vector<int> (m + 1, 0));
        
        queue<pair<int,int>> q;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++)
                if(a[i][j] == 2) q.push({i, j});
        }
        
        int c = 0;
        while(!q.empty()){
            int x = q.size();
            c++;
            for(int k = 0; k < x; k++){
                int i = q.front().first;
                int j = q.front().second;
                q.pop();
                
                if(i - 1 >= 0 and a[i-1][j] == 1) 
                    q.push({i-1, j}), a[i-1][j] = -1;
                
                if(j - 1 >= 0 and a[i][j-1] == 1) 
                    q.push({i, j-1}), a[i][j-1] = -1;
                
                if(i + 1 < n and a[i+1][j] == 1) 
                    q.push({i+1, j}), a[i+1][j] = -1;
                
                if(j + 1 < m and a[i][j+1] == 1) 
                    q.push({i, j+1}), a[i][j + 1] = -1;
            }
        }
        
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                if(a[i][j] == 1){
                    // cout<<i <<" "<< j<<" ";
                    return -1;
                }
        
        if(c)
            return c-1;
        return 0;
    }
};