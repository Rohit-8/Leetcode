class Solution {
public:
    string longestCommonPrefix(vector<string>& s) {
        
        string str = s[0];
        string ans = "";
        
        for(int i = 1; i < s.size(); i++){
            string x = s[i];
            ans = "";
            for(int j = 0; j < min(x.size(), str.size()); j++){
                if(str[j] == x[j]) ans += str[j];
                else break;
            }
            str = ans;
        }
        ans = str;
        return ans;
    }
};