class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        
        unordered_map<char,int> m;
        unordered_map<char,int> m2;
        for(auto x : p){
            m2[x]++;
        }
        vector<int> ans;
        
        if(p.length() > s.length())
            return ans;
        
        int i = 0, j = 0;
        while(i <= s.length() - p.length()){
            
            while(j < i +p.length()){
                m[s[j]]++;
                j++;
            }
            bool flag = true;
            
            for(auto x : m2){
                if(!m.count(x.first)){
                    flag = false; break;
                }
                else if(m[x.first] != x.second){
                    flag = false;
                    break;
                }
            }
            
            if(flag) ans.push_back(i);
            m[s[i]]--;
            if(m[s[i]] == 0) m.erase(s[i]);
            
            i++; 
        }
        
        return ans;
    }
};