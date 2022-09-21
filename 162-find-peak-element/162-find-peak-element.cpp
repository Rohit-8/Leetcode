class Solution {
public:
    int findPeakElement(vector<int>& a) {
        int n = a.size();
        if(n == 1) return 0;
        for(int i = 0; i < n; i++){
            if(i == 0 and a[i] > a[i + 1]) return i;
            else if(i == n - 1 and a[i] > a[i - 1]) return i;
            
            else if(i > 0 and i + 1 < n and a[i] > a[i - 1] and a[i] > a[i + 1])
                return i;
        }
        
        return 0;
    }
};