class Solution {
public:
    vector<int> par, rank;
    int parp(int node){
        if(node == par[node])
            return node;
        return parp(par[node]);
    }
    void unionp(int u, int v){
        u = parp(u);
        v = parp(v);
        
        if(rank[u] == rank[v])
            par[u] = v, rank[v]++;
        else if(rank[u] < rank[v]){
            par[u] = v;
        }
        else par[v] = u;
    }
    
    int findCircleNum(vector<vector<int>>& a) {
        par.resize(a.size() + 1);
        rank.resize(a.size() + 1, 0);
        for(int i = 0; i <= a.size(); i++){
            par[i] = i;
        }
        
        for(int i = 0; i < a.size(); i++){
            for(int j = 0; j < a[0].size(); j++){
                if(i != j and a[i][j]){
                    unionp(i + 1, j + 1);
                }
            }
        }
        
        unordered_set<int> st;
        for(int i = 1; i <= a.size(); i++){
            int x = parp(i);
            st.insert(x);
        }
        
        return st.size();
    }
};