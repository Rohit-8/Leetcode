class Solution {
public:
    string reverseWords(string s) {
        vector<string> v;
        int n = s.size();
        for(int j = 0; j < n; j++){
            if(s[j] == ' ') continue;
            string a = "";
            
            while(j < n and s[j] != ' '){
                a+= s[j]; j++;
            }
            
            while(j + 1 < n and s[j+1] == ' ') j ++;
            v.push_back(a);
        }
        string ans = "";
        ans += v[v.size() - 1];
        for(int i = v.size() -2; i >= 0; i--){
            ans += " ";
            ans += v[i];
        }
        
        return ans;
    }
};