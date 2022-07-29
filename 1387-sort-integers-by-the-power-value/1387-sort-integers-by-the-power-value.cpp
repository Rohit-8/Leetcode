class Solution {
public:
    
    int pow(long long n){
        if(n == 1) return 0;
        int c = 0;
        while(n > 1){
            c ++;
            if(n & 1) n = n * 3 + 1;
            else n /= 2;
        }
        return c;
    }
    
    static bool cmp(pair<int,int> &a, pair<int,int> &b){
        if(a.first != b.first) return a.first < b.first;
        return a.second < b.second;
    }
    
    int getKth(int lo, int hi, int k) {
        vector<pair<int,int>> v;
        
        for(int i = lo; i <= hi; i++){
            v.push_back({pow(i*1ll), i});
        }
        sort(begin(v), end(v), cmp);
        
        return v[k-1].second;
    }
};