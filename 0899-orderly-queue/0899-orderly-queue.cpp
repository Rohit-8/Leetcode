class Solution {
public:
    string orderlyQueue(string s, int k) {
        string tmp=s;
        string ans=tmp;
        for(int i=0;i<s.length();i++)
        {
            if(ans>tmp) ans=tmp;
            
            char c = tmp[0];
            reverse(tmp.begin(),tmp.end());
            tmp.pop_back();
            reverse(tmp.begin(),tmp.end());
            tmp.push_back(c);
        }
        
        if(k==1)
        return ans;
        else
        {
            sort(s.begin(),s.end());
            return s;
        }
    }
};