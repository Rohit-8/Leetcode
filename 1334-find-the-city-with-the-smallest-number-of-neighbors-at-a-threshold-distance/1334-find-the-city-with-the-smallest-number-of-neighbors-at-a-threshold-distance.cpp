class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& a, int dt) {
        
        vector<vector<long long>> dist(n, vector<long long> (n, INT_MAX));
        
        for(int i = 0; i < n; i++)
            dist[i][i] = 0;
        
        for(auto x: a){
            dist[x[0]][x[1]] = x[2];
            dist[x[1]][x[0]] = x[2];
        }
        
        for(int k = 0; k < n; k++){
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                
                    if(dist[i][k] + dist[k][j] < dist[i][j]){
                        dist[i][j] = dist[i][k] + dist[k][j];
                    }
                }
            }
        }
        
        int ans = 0;
        int prev = INT_MAX;
        for(int i = 0; i < n; i++){
            int c = 0;
            for(int j = 0; j < n; j++){
                if(i != j and dist[i][j] <= dt) c++;
            }
            if(c <= prev) ans = i, prev = c;
        }
        
        return ans;
    }
};