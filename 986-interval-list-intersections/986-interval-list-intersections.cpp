class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& fl, vector<vector<int>>& sl) {
        vector<vector<int>> ans;
        int n = fl.size();
        
        int j = 0;
        for(int i = 0; i < sl.size() and j < n; ){
            if((sl[i][0] >= fl[j][0] and sl[i][0] <= fl[j][1]) or (sl[i][0] < fl[j][0] and sl[i][1] >= fl[j][0])){
                ans.push_back({max(sl[i][0], fl[j][0]), min(sl[i][1], fl[j][1])});
                if(sl[i][1] > fl[j][1]) j++;
                else if(sl[i][1] < fl[j][1]) i++;
                else i++, j++;
                
            }
            else if(sl[i][0] > fl[j][1]) j++;
            else i++;
        }
        
        return ans;
        
    }
};