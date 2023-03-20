class Solution {
public:
    int res(vector<int> &a, int i, int k, vector<int> &v){
        if(i >= a.size())
            return 0;
        
        int sum = res(a, i + 1, k, v);
        for(int j = 0; j < v.size(); j++){
            if(abs(a[i] - v[j]) == k)
                return sum;
        }
        
        v.push_back(a[i]);
        sum += 1 + res(a, i + 1, k, v);
        v.pop_back();
        return sum;
    }
    int beautifulSubsets(vector<int>& a, int k) {
        vector<int> v;
        return res(a, 0, k, v);
    }
};