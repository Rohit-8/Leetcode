#define ll long long
class Solution {
public:
    double myPow(double x, int m) {
        
        ll n = m;
        if(n<0) n*=(-1);
        
        double ans = 1;
        while(n>0){
            if(n%2==0) x*=x, n/=2;
            else ans*=x, n--;
        }
        
        if(m<0) ans = 1.0/ans;
        
        return ans;
    }
};