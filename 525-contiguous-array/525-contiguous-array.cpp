class Solution {
public:
    int findMaxLength(vector<int>& a) {
        int ans = 0;
            
        unordered_map<int, int> m;
        int sum = 0;
        for(int i = 0; i < a.size(); i++){
            if(a[i] == 0) sum --;
            else sum ++;
            
            if(sum == 0){
                ans = i+1; continue;
            }
            
            if(m[sum] > 0) ans = max(ans,i - m[sum] + 1);
            else m[sum] = i + 1;
        }
        
        return ans;
    }
};