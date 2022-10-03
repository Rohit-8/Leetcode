class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& a, vector<int>& b) {
        vector<vector<int>> ans;
        int p = -1;
        bool f = true;
        for(int i = 0; i < a.size(); i++){
            if(!f){
                ans.push_back(a[i]);
                continue;
            }
            
            else if(b[0] <= a[i][0] and b[1] >= a[i][0] or 
              b[0] >= a[i][0] and b[0] <= a[i][1]){
                
                int j = i;
                while(i < a.size() and b[1] >= a[i][0]) i++;
                
                i--;
                ans.push_back({min(b[0], a[j][0]), max(b[1], a[i][1])});
                f = false;
            }
            else if(b[1] < a[i][1]){
                ans.push_back(b);
                i--;
                f = false;
            }
            else ans.push_back(a[i]);
        }
        if(f) ans.push_back(b);
        return ans;
    }
};