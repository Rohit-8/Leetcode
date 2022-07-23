class Solution {
public:
    
    int cc;
    int res(vector<int> &a, int k, int n, vector<bool> &v, int sum, int i){
        if(k == 1) return true;
        
        if(i == n) return false;
        
        if(sum == cc)
            return res(a, k-1, n, v, 0, 0);
        
        for(; i < n; i++){
            if(a[i] + sum <= cc and v[i] == false){
                v[i] = true;
                bool x = res(a, k, n, v, sum + a[i], i+1);
                if(x == true) return true;
                v[i] = false;
            }
        }
        
        return false;
    }
    
    bool canPartitionKSubsets(vector<int>& a, int k) {
        if(k == 1) return true;
        int sum = 0;
        for(int i = 0; i < a.size(); i++){
            sum += a[i];
        }
        if(sum % k or a.size() < k) return false;
        
        cc = sum / k;
        vector<bool> v(17, false);
        return res(a, k, a.size(), v, 0, 0);
    }
};