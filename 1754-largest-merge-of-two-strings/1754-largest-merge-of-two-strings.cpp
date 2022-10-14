class Solution {
public:
    string largestMerge(string s, string t) {
        string ans = "";
        int i = 0, j = 0;
        for(; i < s.size() and j < t.size(); ){
            if(s[i] > t[j]) ans += s[i++];
            else if(t[j] > s[i]) ans += t[j++];
            
            else {
                int k = i + 1, l = j + 1;
                while(k < s.size() and l < t.size() and s[k] == t[l]){
                    l ++, k ++;
                }
                if(l >= t.size())
                    ans += s[i++];
                else if(k >= s.size())
                    ans += t[j++];
                
                else if(s[k] > t[l]) ans += s[i++];
                else ans += t[j++];
            }
        }
        
        while(j < t.size()) ans += t[j++];
        while(i < s.size()) ans += s[i++];
        
        return ans;
    }
};