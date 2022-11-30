class Solution {
public:
    int minDeletion(vector<int>& a) {
        int n = a.size(), x = 0;
        for(int i = 0; i < n; i++){
            if(i + 1 < n and a[i] == a[i + 1])
                x++;
            else i++;
        }
        if((n - x) % 2) x++;
        
        return x;
    }
};