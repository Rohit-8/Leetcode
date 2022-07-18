class Solution {
public:
    int hIndex(vector<int>& a) {
        int ans = 0;
        for(int i = (int)a.size()-1; i >= 0 && ans < a[i];i--) 
            ans = max(ans, (int)a.size()-i);
        
        return ans;
    }
};