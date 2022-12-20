class Solution {
public:
    int minNumberOperations(vector<int>& a) {
        int ans = a[0];
        for(int i = 1; i < a.size(); i++){
            if(a[i] > a[i - 1]){
                ans += a[i] - a[i - 1];
            }
        }
        
        return ans;
    }
};