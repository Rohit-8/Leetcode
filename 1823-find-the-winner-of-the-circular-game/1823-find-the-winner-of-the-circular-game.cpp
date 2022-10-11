class Solution {
public:
    
    void res(vector<int> &s, int i, int k){
        if(s.size() <= 1) return;
        
        int pos = (i + k - 1) % s.size();
        s.erase(s.begin() + pos);
        res(s, pos, k);
        return;
    }
    
    int findTheWinner(int n, int k) {
        vector<int> a(n);
        for(int i = 1; i <= n; i++){
            a[i - 1] = i;
        }
        
        res(a, 0, k);
        return a[0];
    }
};