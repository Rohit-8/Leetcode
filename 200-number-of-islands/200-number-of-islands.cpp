class Solution {
public:

    void dfs(vector<vector<pair<char,int>>>& v ,int i,int j){
        
        if(i<0 or i>=v.size() or j<0 or j>=v[0].size() or v[i][j].first!='1' or v[i][j].second ==1) 
            return;
        
        v[i][j].second=1;
        
        dfs(v,i+1,j);
        dfs(v,i-1,j);
        dfs(v,i,j+1);
        dfs(v,i,j-1);   
    }
    
    int numIslands(vector<vector<char>>& grid) {
        
        vector<vector<pair<char,int>>> v(grid.size());
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++)
                v[i].push_back({grid[i][j],0});  
        }
        
        int ans=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++)
                if(v[i][j].first=='1' and v[i][j].second==0){
                    dfs(v,i,j);
                    ans++;
                }
        }
        
        return ans;
    }
};