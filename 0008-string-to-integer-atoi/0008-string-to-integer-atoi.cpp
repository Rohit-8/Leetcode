class Solution {
public:
    int myAtoi(string &s) {
        if(s.size() == 0) return 0;
        int i = 0;
        while(i < s.size() and s[i] == ' ') i++;
        
        long mul = 1;
        if(s[i] == '-') mul = -1, i++;
        else if(s[i] == '+') i++;
        if(i >= s.size()) return 0;
        
        long ans = 0;
        for(; i < s.size(); i++){
            if(s[i] < '0' or s[i] > '9') break;
            ans = ans * 10 + (s[i] - '0');
            if(ans >= INT_MAX and mul == 1){
                // cout<<ans;
                return INT_MAX;
            }
            else if(ans > INT_MAX and mul == -1){
                return INT_MIN;
            }
        }
        
        return ans * mul;
    }
};