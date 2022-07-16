class Solution {
public:
    int removeDuplicates(vector<int>& a) {
        int n = a.size();
        int j = -1;
        
        int ans = 1;
        for(int i = 1; i < n; i++){
            if(a[i] != a[i-1]) ans++;
            if(a[i] != a[i-1] and j != -1)
                a[j] = a[i], j++;
            else if(a[i] == a[i-1] and j == -1)
                j = i;
            
        }
        
        return ans;
    }
};