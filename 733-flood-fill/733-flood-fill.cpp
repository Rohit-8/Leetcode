class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        queue<pair<int,int>> q;
        q.push({sr,sc});
        vector<vector<int>> vis(image.size(),vector<int>(image[0].size(),-1));
        vis[sr][sc]=1;
        // image[sr][sc]=color;
        
        while(!q.empty()){
            int i=q.front().first;
            int j=q.front().second;
            q.pop();
            
            if((i-1)>=0 and image[i][j]==image[i-1][j] and vis[i-1][j]==-1){
                vis[i-1][j]=1;
                q.push({i-1,j});
            }
            if((i+1)<image.size() and image[i][j]==image[i+1][j] and vis[i+1][j]==-1){
                vis[i+1][j]=1;
                q.push({i+1,j});
            }
            if((j-1)>=0 and image[i][j]==image[i][j-1] and vis[i][j-1]==-1){
                vis[i][j-1]=1;
                q.push({i,j-1});
            }
            if((j+1)<image[0].size() and image[i][j]==image[i][j+1] and vis[i][j+1]==-1){
                vis[i][j+1]=1;
                q.push({i,j+1});
            }
            image[i][j] = color;
        }
        return image;
    }
};