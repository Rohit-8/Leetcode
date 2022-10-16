class Solution {
public:
    int rev(int n){
        int sum = 0;
        for(int i = n; i > 0; i /= 10){
            sum = sum * 10 + (i % 10);
        }
        return sum;
    }
    
    bool sumOfNumberAndReverse(int n) {
        if(n == 0) return true;
        
        for(int i = 1; i < n; i++){
            if(i + rev(i) == n)
                return true;
        }
        
        return false;
    }
};