#define ll long long
class Solution {
public:
    ll MOD = 1000000007;
    int delay,forget;
    vector<ll> memo;
    
    long dp(int n) {
        if(!n)
            return 0;
        if(memo[n]!=-1)
            return memo[n];
		
        ll result=1;
        for(int i=delay;i<forget;i++)
            if(n-i>=0)
                result=(result+dp(n-i))%MOD;
        return memo[n]=result;
    }
    
    int peopleAwareOfSecret(int n, int delay, int forget) {
        this->delay=delay;
        this->forget=forget;
        memo.resize(n+1,-1);
        return (dp(n)-dp(n-forget)+MOD)%MOD;
    }
};