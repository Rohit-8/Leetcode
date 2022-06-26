class Solution {
public:
    int n, m;
    int dfs(vector<vector<int>>& v,int i,int j){

        if(i<0 or i>=n or j<0 or j>=m or v[i][j]==0)
            return 0;

        v[i][j]=0;
        int ans = 1;
        for(int k = 0; k< m; k++){
            if(v[i][k]==1) 
                ans += dfs(v,i,k);
        }
        for(int k = 0; k<n;k++){
            if(v[k][j]==1) 
                ans += dfs(v,k,j);
        }

        return ans;
    }

    int countServers(vector<vector<int>>& v) {

        int ans = 0;
        n = v.size(), m= v[0].size();

        for(int i =0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(v[i][j] == 1){
                    int x = dfs(v,i,j);
                    if(x>1)
                    ans += x;
                }
            }

        }

        return ans;
    }
};