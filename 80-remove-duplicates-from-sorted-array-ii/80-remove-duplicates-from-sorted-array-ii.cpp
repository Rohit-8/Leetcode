class Solution {
public:
    int removeDuplicates(vector<int>& a) {
        
        if (a.size() <= 2) return a.size();
        
        int ans = 2;
        for (int i = 2; i < a.size(); i++) {
            if (a[i] != a[ans-2]) {
                a[ans] = a[i]; ans ++;
            }
        }
        return ans;
    }
};