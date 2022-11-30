class Solution {
public:
    vector<int> ans;
    int prev = 0;
    void res(vector<int> &a, int x, vector<int> v, int n, int sum){
        if(n < 0 or x <= 0){
            if(x > 0) v[0] += x;
            if(sum >= prev){
                ans = v;
                prev = sum;
            }
            return;
        }
        res(a, x, v, n - 1, sum);
        if(x > a[n]){
            v[n] = a[n] + 1;
            res(a, x - a[n] - 1, v, n - 1, sum + n);
            v[n] = 0;
        }
        return;
    }
    vector<int> maximumBobPoints(int x, vector<int>& a) {
        vector<int> v(a.size(), 0);
        
        // ans.resize(a.size(), 0);
        res(a, x, v, a.size() - 1, 0);
        
        return ans;
    }
};