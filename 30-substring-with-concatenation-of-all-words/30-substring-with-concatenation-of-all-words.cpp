class Solution {
public:
    
    bool res(unordered_map<string, int> mp, string s, int n) {
        for (int i = 0; i < s.length(); i += n) {
            if(mp[s.substr(i, n)]--) continue;
            return false;
        }
        return true;
    }
    
    vector<int> findSubstring(string s, vector<string>& a) {
        
        unordered_map<string, int> mp;
        for (int i = 0; i < a.size(); ++i) {
            mp[a[i]]++;
        }
        
        int pl = a.size() * a[0].size();
        vector<int> ans;
        
        int i = 0;
        while (i + pl <= s.length()) {
            if (res(mp, s.substr(i, pl), a[0].size()))
                ans.push_back(i);
            i++;
        }
        
        return ans;
    }
};