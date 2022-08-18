class Solution {
public:
    
    bool res(long long l, long long r, string s, bool f){
        if(s.size() == 0 and f)
            return 1;
        
        string sum = to_string(l+r);
        int n = min(s.size(), sum.size());
        if(s.substr(0, n) == sum){
            return res(r, stol(sum), s.substr(n), true);
        }
        return 0;
    }
    
    bool isAdditiveNumber(string a) {
        for(int i = 1; i <= a.size()/2; i++){
            
            long long l = stol(a.substr(0, i));
            if(to_string(l) != a.substr(0, i)){
                break;
            }
            for(int j = i + 1; j < a.size(); j++){
                long long r = stol(a.substr(i, j-i));
                if(to_string(r) != a.substr(i, j-i))
                    break;
                if(res(l, r, a.substr(j), false))
                    return true;
            }
        }
        return false;
    }
};