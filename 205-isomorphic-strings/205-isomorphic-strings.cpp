class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map<char, char> m, m2;
        for(int i = 0; i < s.size(); i++){
            if(m.find(s[i]) != m.end() and m2.find(t[i]) != m2.end()){
                if(m[s[i]] != t[i] or m2[t[i]] != s[i])
                    return false;
            }
            else if(m.find(s[i]) == m.end() and m2.find(t[i]) == m2.end()){
                m[s[i]] = t[i];
                m2[t[i]] = s[i];
            }
            else return false;
        }
        
        return true;
    }
};