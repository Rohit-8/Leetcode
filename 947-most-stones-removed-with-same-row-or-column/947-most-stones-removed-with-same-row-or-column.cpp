class Solution {
public:
    
    int par[10001], ran[10001];

    void setParRank(int n){
      for(int i = 0; i <= n; i++){
        par[i] = i; ran[i] = 0;
      }
    }

    int findpar(int node){
        if(node == par[node]) return node;
        return par[node] = findpar(par[node]);
    }

    void unionp(int u, int ans){

        u = findpar(u);
        ans = findpar(ans);
        if(ran[u] < ran[ans])
            par[u] = ans;
        else if(ran[u] > ran[ans])
            par[ans] = u;
        else{
            par[ans] = u;
            ran[u]++;
        }
    }
    
    int removeStones(vector<vector<int>>& st) {
        int n = st.size();
        setParRank(n + 1);
        
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(st[i][0] == st[j][0] or st[i][1] == st[j][1])
                    unionp(i,j);
            }
        }
        
        set<int> a;
        for(int i = 0;i < n; i++){
            int t = findpar(i);
            a.insert(t);
        }
        
        return n - a.size();
    }
};