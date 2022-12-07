class Solution {
public:
    
    vector<vector<int>> ans;
    void res(vector<int> &a, int t, int n, vector<int> v, int sum, int i){
        if(sum == t){
            ans.push_back(v);
            return;
        }
        if(i >= n) return ;
        
        for( ; i < n; i ++){
            if(sum + a[i] <= t){
                v.push_back(a[i]);  
                res(a, t, n, v, sum + a[i], i);
                v.pop_back();
                while(i+1 < n and a[i+1] == a[i]) i++;
            }
            // else return;
        }
        return;
    }
    
    vector<vector<int>> combinationSum(vector<int>& a, int t) {
        vector<int> v;
        res(a, t, a.size(), v, 0, 0);
        
        return ans;
    }
};