class Solution {
public:
    int res(vector<int> &a, int i, int k, vector<int> &v){
        if(i >= a.size())
            return 0;
        
        int sum = res(a, i + 1, k, v);
        if(binary_search(v.begin(), v.end(), a[i] - k) == 1)
            return sum;
        
        v.push_back(a[i]);
        sum += 1 + res(a, i + 1, k, v);
        v.pop_back();
        return sum;
    }
    int beautifulSubsets(vector<int>& a, int k) {
        vector<int> v;
        sort(a.begin(), a.end());
        return res(a, 0, k, v);
    }
};