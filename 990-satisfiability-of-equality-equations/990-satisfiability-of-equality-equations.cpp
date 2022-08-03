class Solution {
public:
    
    bool equationsPossible(vector<string>& a) {
        int n = a.size();
        int col[26] = {0};
        
        vector<int> adj[26];
        for(auto x: a){
            if(x[1] == '=')
            adj[x[0]-'a'].push_back(x[3]-'a'),
            adj[x[3]-'a'].push_back(x[0]-'a');
        }
        int t = 0;
        
        for(int i = 0; i < 26; i++){
            if(col[i] == 0){
                t ++;
                queue<int> q;
                q.push(i);
                while(!q.empty()){
                    int x = q.front();
                    q.pop(); col[x] = t;
                    for(auto c : adj[x]){
                        if(col[c] == 0)
                            q.push(c);
                    }
                }
            }
        }
        for(auto s: a){
            if(s[1] == '=') continue;
            int x = s[0]-'a', y = s[3]-'a';
            if(x == y or col[x] == col[y]) return false;
        }
        
        return true;
    }
};