class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& a) {
        
        int c = 0, ans = 0;
        for(int i = 0; i < a.size(); i++){
            if(a[i] == 1) c++;
            else c = 0;
            ans = max(ans, c);
        }
        
        return ans;
    }
};