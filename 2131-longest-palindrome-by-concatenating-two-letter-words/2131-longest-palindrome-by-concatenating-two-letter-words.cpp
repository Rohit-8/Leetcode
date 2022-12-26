class Solution {
public:
    int longestPalindrome(vector<string>& a) {
        int n = a.size();
        unordered_map<string, int> mp;
        for(int i = 0; i < n; i++){
            mp[a[i]] ++;
        }
        
        int ans = 0;
        for(int i = 0; i < n; i++){
            if(mp[a[i]] <= 0)
                continue;
            
            string s = a[i];
            int c = 0;
            reverse(s.begin(), s.end());
            if(s == a[i])
                c ++;
            if(mp[s] > c){
                ans += 4;
                mp[a[i]] --;
                mp[s] --;
            }
        }
        
        for(int i = 0; i < n; i++){
            if(mp[a[i]] <= 0)
                continue;
            if(a[i][0] == a[i][1]){
                ans += 2;
                break;
            }
        }
        
        return ans;
    }
};