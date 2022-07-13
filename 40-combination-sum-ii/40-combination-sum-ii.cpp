class Solution {
public:
    
    vector<vector<int>> ans;
    set<vector<int>> st;
    void res(vector<int> &a, int t, int n, vector<int> &v, int &sum, int i){
        
        if(sum == t){
            ans.push_back(v);
            return;
        }
        
        if(i >= n) return;
        
        for( ; i < n; i ++){
            
            if(sum + a[i] <= t){
                v.push_back(a[i]); 
                sum = sum + a[i];
                res(a, t, n, v, sum, i + 1);
                v.pop_back();
                sum -= a[i];
                
                while(i+1 < n and a[i+1] == a[i]) i++;
            }
            else return;
        }
        return;
    }
    
    vector<vector<int>> combinationSum2(vector<int>& a, int t) {
        
        vector<int> v;
        sort(a.begin(), a.end());
        int sum = 0;
        res(a, t, a.size(), v, sum, 0);
        
        // for(auto x: st)
        //     ans.push_back(x);
        
        return ans;
    }
};