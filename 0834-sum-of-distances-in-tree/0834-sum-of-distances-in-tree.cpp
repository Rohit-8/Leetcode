class Solution {
private:
    vector<int> sub;
    vector<int> sum;
    vector<int> dept;
    vector<bool> vis;

    void dfs1(vector<int> adj[], int parent) {
        vis[parent] = true;
        sub[parent] = 1;
        for(auto child : adj[parent]) {
            if(!vis[child]) {
                vis[child] = true;
                dept[child] = dept[parent] + 1;
                dfs1(adj,child);
                sub[parent] = sub[parent] + sub[child];
            }
        }
    }

    void dfs2(vector<int> adj[], int parent, int n) {
        vis[parent] = true;
        for(auto child : adj[parent]) {
            if(!vis[child]) {
                sum[child] = sum[parent] - sub[child] + (n - sub[child]);
                dfs2(adj,child, n);
            }
        }
    }

public:
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        int N = edges.size();
        sum.resize(n);
        sub.resize(n);
        dept.resize(n);
        vis.resize(n);

        vector<int> adj[n];

        for(int i=0;i<N;i++) {
            int u = edges[i][0];
            int v = edges[i][1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        for(int i=0;i<n;i++) {
            vis[i] = false;
        }

        dfs1(adj, 0);
        for(int i=0;i<n;i++) {
            sum[0] += dept[i];
        }
        
        for(int i=0;i<n;i++) {
            vis[i] = false;
        }

        dfs2(adj,0,n);
        return sum;
    }
};