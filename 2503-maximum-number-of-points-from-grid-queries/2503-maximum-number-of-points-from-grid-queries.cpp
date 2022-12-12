class Solution {
public:
    vector<int> maxPoints(vector<vector<int>>& a, vector<int>& qp) {
        vector<int> q = qp;
        sort(q.begin(), q.end());
        int n = a.size(), m = a[0].size();
        
        int k = 0;
        int nn = q.size();
        
        priority_queue <pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        
        pq.push({a[0][0], {0, 0}});
        vector<int> v(1000001, 0);
        
        vector<vector<int>> vis(n , vector<int> (m, 0));
        vis[0][0] = 1;
        
        int c = 0;
        while(!pq.empty() and k < nn){
            int el = pq.top().first;
            
            if(el >= q[k]){
                v[q[k]] = c;
                k++;
                continue;
            }
            
            int i = pq.top().second.first;
            int j = pq.top().second.second;
            
            pq.pop();
            c++;
            // a[i][j] = -1;
            //// up /////
            if(i - 1 >= 0 and vis[i - 1][j] == 0){
                pq.push({a[i - 1][j], {i - 1, j}});
                vis[i - 1][j] = 1;
            }
            //// down ////
            if(i + 1 < n and vis[i + 1][j] == 0){
                pq.push({a[i + 1][j], {i + 1, j}});
                vis[i + 1][j] = 1;
            }
            //// left ////
            if(j - 1 >= 0 and vis[i][j - 1] == 0){
                pq.push({a[i][j - 1], {i, j - 1}});
                vis[i][j - 1] = 1;
            }
            //// right ////
            if(j + 1 < m and vis[i][j + 1] == 0){
                pq.push({a[i][j + 1], {i, j + 1}});
                vis[i][j + 1] = 1;
            }
            
        }
        while(k < nn){
            // cout << " ds "<< c << " d ";
            v[q[k]] = c;
            k++;
        }
        vector<int> ans(nn);
        for(int i = 0; i < nn; i++){
            ans[i] = v[qp[i]];
        }
        
        return ans;
    }
};