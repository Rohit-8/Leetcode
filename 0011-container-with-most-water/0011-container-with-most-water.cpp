class Solution {
public:
    int maxArea(vector<int>& h) {
        int n = h.size();
        int i = 0, j = n - 1;
        int ans = min(h[i], h[j])*(j-i);
        
        for(; i<j;){
            if(h[i]>h[j]) j--;
            else i++;
            ans = max(ans,min(h[i], h[j])*(j-i));
        }
        return ans;
    }
};