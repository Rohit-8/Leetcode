class Solution {
public:
    vector<vector<int>> ans;
    void res(int i, vector<int> &a){
        if(i == a.size()){
            ans.push_back(a);
            return;
        }
        for(int j = i; j<a.size(); j++){
            swap(a[i],a[j]);
            res(i+1,a);
            swap(a[i],a[j]);
        }
    }
    
    vector<vector<int>> permute(vector<int>& a) {
        res(0 , a);
        return ans;
    }
};