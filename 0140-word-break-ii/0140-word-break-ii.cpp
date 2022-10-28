class Solution {
public:
    
    vector<string> ans;
    void res(string &s, int n, string st, map<string, int> m){
        if(n >= s.size()){
            st.pop_back();
            ans.push_back(st);
            return;
        }
        string a = "";
        for(int i = n; i < s.size(); i++){
            a += s[i];
            if(m[a] > 0){
                // m[a]--;
                st += a;
                st += " ";
                res(s, i + 1, st, m);
                st.pop_back();
                for(int k = 0; k < a.size(); k++){
                    st.pop_back();
                }
                // m[a]++;
            }
        }
    }
    
    vector<string> wordBreak(string s, vector<string>& w) {
        map<string, int> m;
        for(int i = 0; i < w.size(); i++){
            m[w[i]]++;
        }
        res(s, 0, "", m);
        
        return ans;
    }
};