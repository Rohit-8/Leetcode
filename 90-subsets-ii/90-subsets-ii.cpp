class Solution {
public:
    vector<vector<int>> ans;

    void res(vector<int> &v, int i, vector<int> &a){
        
        ans.push_back(v);
        for(int j = i; j < a.size(); j++){
            if(j != i && a[j] == a[j-1])
                continue;
            
            v.push_back(a[j]);
            res(v, j + 1, a);
            
            v.pop_back();
        }
        return;
    }

    vector<vector<int>> subsetsWithDup(vector<int>& a) {
        vector<int> t;
        sort(a.begin(), a.end());
        
        res(t, 0, a);
        return ans;
    }
};