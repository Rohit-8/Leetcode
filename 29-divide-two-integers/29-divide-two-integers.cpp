class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend==divisor)return 1;
        if(dividend == INT_MIN){
            if(divisor == 1) return INT_MIN;
        }
        
        bool sign=(dividend<0 == divisor<0);
        unsigned int a=abs(dividend);
        unsigned int b=abs(divisor);
        int ans=0;
        
        while(a>=b)
        {
            int cnt=0;
            while(a> (b<<(cnt+1)))
                  cnt++;
            if(ans==(1<<31) && sign)
            return INT_MAX;
            if((unsigned)ans + (1<<cnt) > INT_MAX) return INT_MAX;
            ans+=(1<<cnt);
          a=a-(b<<cnt);
        }
        
            return sign?ans:-ans;
    }
};