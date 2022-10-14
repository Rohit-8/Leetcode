class Solution {
public:
    bool res(string &s, string &t){
        string a, b;
        for(int i = 0; i < s.size(); i++){
            if(s[i] != '_') a += s[i];
            if(t[i] != '_') b += t[i];
        }
        return a == b;
    }
    
    bool canChange(string &s, string &t) {
        if(res(s, t) == false)
            return false;
        
        vector<int> l1, r1, l2, r2;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == 'L') l1.push_back(i);
            else if(s[i] == 'R') r1.push_back(i);
            
            if(t[i] == 'L') l2.push_back(i);
            else if(t[i] == 'R') r2.push_back(i);
        }
        
        for(int i = 0; i < l1.size(); i++){
            if(l2[i] > l1[i]) return false;
        }
        for(int i = 0; i < r2.size(); i++){
            if(r2[i] < r1[i]) return false;
        }
        
        return true;
    }
};