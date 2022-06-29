class Solution {
public:
    static bool comp(vector<int> &a,vector<int> &b){
        if(a[0]==b[0]) return a[1]<b[1];
        return a[0]>b[0];
    }
    vector<vector<int>> reconstructQueue(vector<vector<int>>& p) {
        
        sort(p.begin(),p.end(),comp);
        vector<vector<int>> ans;
        
        for(auto it:p){
            ans.insert(ans.begin()+it[1],it);
        }
        return ans;
    }
};