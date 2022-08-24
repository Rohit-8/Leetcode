class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n <= 0) return false;
        while(n > 0){
            if(n == 3 or n == 1) return true;
            if(n % 3) return false;
            n /= 3;
        }
        return false;
    }
};