class Solution {
public:
    bool isPowerOfFour(int n) {
        return n > 0 and !(n&(n-1)) && (n&0x55555555);
    }
};