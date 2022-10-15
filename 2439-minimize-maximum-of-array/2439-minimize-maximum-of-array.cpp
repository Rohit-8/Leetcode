class Solution {
public:
    int minimizeArrayValue(vector<int>& a) {
        
        long sum = a[0];
        int mx = a[0];
        for(int i = 1; i < a.size(); i++){
            sum += a[i];
            mx = max(mx, (int)((sum/ (i + 1)) + ((sum % (i + 1))? 1: 0)));
        }
        
        return mx;
    }
};