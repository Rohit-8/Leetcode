class Solution {
public:
    bool isPossible(int n, vector<vector<int>>& a) {
        vector<int> od, in(n + 1, 0);
        vector<map<int, int>> mp(n + 1);
        for(int i = 0; i < a.size(); i++){
            in[a[i][0]]++;
            in[a[i][1]]++;
            mp[a[i][0]][a[i][1]]++;
            mp[a[i][1]][a[i][0]]++;
        }
        
        for(int i = 1; i <= n; i++){
            if(in[i] % 2){
                od.push_back(i);
            }
        }
        if(od.size() == 0)
            return true;
            
        if(od.size() > 4 or od.size() % 2)
            return false;
        
        if(od.size() == 2){
            
            if(mp[od[0]][od[1]] <= 0)
                return true;
            for(int i = 1; i <= n; i++){
                map<int, int> m = mp[i];
                if(i != od[0] and i != od[1] and m[od[0]] <= 0 and m[od[1]] <= 0)
                    return true;
            }
            return false;
        }
        
        map<int, int> m = mp[od[0]];
        for(int i = 1; i < 4; i++){
            if(m.count(od[i]) == false){
                int x, y;
                if(i == 1){
                    x = 2, y = 3;
                }
                if(i == 2) x = 1, y = 3;
                if(i == 3) x = 1, y = 2;
                
                if(mp[od[x]].count(od[y]) == false)
                    return true;
            }
        }
        
        return false;
    }
};