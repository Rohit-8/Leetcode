class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& a) {
        sort(a.begin(), a.end());
        
        vector<vector<int>> ans;
        int first = a[0][0],second = a[0][1];
        
        for(int i = 1; i< a.size(); i++){
           if(a[i][0]>second){
                ans.push_back({first,second});
               first = a[i][0]; second = a[i][1];
           }
            else second = max(a[i][1],second);
            
        }
        ans.push_back({first,second});
        
        return ans;
    }
};