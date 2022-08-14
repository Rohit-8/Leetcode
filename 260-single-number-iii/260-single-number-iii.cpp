class Solution {
public:
    vector<int> singleNumber(vector<int>& a) {
        int x = 0;
        
        for(int i = 0; i < a.size(); i++){
            x ^= a[i];
        }
        
        int c = 0;
        while(1){
            if(x & (1<<c)) break;
            c++;
        }
        
        int y = 0; x = 0;
        for(int i = 0; i < a.size(); i++){
            if(a[i] & (1<<c)) y ^= a[i];
            else x ^= a[i];
        }
        
        return {x, y};
    }
};