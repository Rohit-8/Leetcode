class Solution {
public:
    vector<string> findAllRecipes(vector<string>& rec, vector<vector<string>>& ing, vector<string>& sup) {
        unordered_map<string, int> sp;
        for(int i = 0; i < sup.size(); i++){
            sp[sup[i]] ++;
        }
        vector<string> ans;
        unordered_map<string, int> mp;
        int n = rec.size();
        for(int jh = 0; jh < n; jh++){
            
            int c = 0;
            for(int i = 0; i < n; i++){
                if(mp.count(rec[i])){
                    c ++;
                    continue;
                }
                
                bool f = true;
                for(int j = 0; j < ing[i].size(); j++){
                    if(sp.count(ing[i][j]) == false){
                        f = false;
                        break;
                    }
                }
                if(f){
                    sp[rec[i]] ++;
                    mp[rec[i]] ++;
                    c ++;
                }
            }
            if(c == 0) break;
        }
        
        for(int i = 0; i < n; i++){
            if(mp.count(rec[i]))
                ans.push_back(rec[i]);
        }
        
        return ans;
    }
};