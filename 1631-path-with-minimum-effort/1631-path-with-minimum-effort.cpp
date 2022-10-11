class Solution {
public:
    
    bool f = false;
    void res(vector<vector<int>> &a, int i, int j, int k, int par, vector<vector<int>> &vis){
        if(f) return;
        if(i < 0 or j < 0 or i >= a.size() or j >= a[0].size() or vis[i][j] == 1)
            return ;
        
        if(abs(par - a[i][j]) > k) return;
        if(i == a.size() - 1 and j == a[0].size() - 1){
            f = true; return;
        }
        vis[i][j] = 1;
        res(a, i + 1, j, k, a[i][j], vis);
        if(f) return;
        res(a, i, j + 1, k, a[i][j], vis);
        if(f) return;
        
        res(a, i - 1, j, k, a[i][j], vis);
        if(f) return;
        res(a, i, j - 1, k, a[i][j], vis);
        return;
    }
    
    int minimumEffortPath(vector<vector<int>>& a) {
        int n = a.size(), m = a[0].size();
        if(n == 1 and m == 1) return 0;
        
        int l = 0, r = 1e7;
        int ans = INT_MAX;
        
        while(l <= r){
            int mid = l + (r - l) / 2;
            f = false;
            vector<vector<int>> vis(a.size(), vector<int> (a[0].size(), 0));
            res(a, 0, 0, mid, a[0][0], vis);
            // vector<vector<int>> x(a.size(), vector<int> (a[0].size(), -1));
            // res(a, 1, 0, mid, a[0][0], x);
            
            if(f) ans = mid, r = mid - 1;
            else l = mid + 1;
        }
        
        return ans;
    }
};