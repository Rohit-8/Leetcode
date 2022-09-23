class Solution {
public:
    bool rotateString(string s, string t) {
        if(s.size() != t.size()) return false;
        vector<int> v;
        
        for(int i = 0; i < s.size(); i++){
            if(s[i] == t[0]) v.push_back(i);
        }
        for(int k = 0; k < v.size(); k++){
            int j, i = v[k];
            for(j = 0; j < t.size(); i++, j++){
                if(s[i] != t[j]) break;
                if(i + 1 >= s.size()) i = -1;
            }
            if(j >= t.size()) return true;
        }
        
        return false;
    }
};