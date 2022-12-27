class Solution {
public:
    int strStr(string a, string b) {
        if(b.size() > a.size())
            return -1;
        for(int i = 0; i < a.size() - b.size() + 1; i ++){
            int j = 0;
            while(j < b.size() and j + i < a.size() and a[j + i] == b[j]) j++;
            if(j >= b.size())
                return i;
        }
        return -1;
    }
};