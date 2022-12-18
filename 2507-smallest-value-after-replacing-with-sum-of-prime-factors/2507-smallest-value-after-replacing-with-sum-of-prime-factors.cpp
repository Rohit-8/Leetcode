class Solution {
public:
    const int MAXN = 100005;

    int getPrimeFactorSum(int x) {
        // Implement a function for computing the sum of the prime factors of x here
        // For example, using trial division:
        int sum = 0;
        for (int i = 2; i <= x / i; i++) {
            while (x % i == 0) {
                sum += i;
                x /= i;
            }
        }
        if (x > 1) {
            sum += x;
        }
        return sum;
    }
    
    int getFactorization(int x){
        return getPrimeFactorSum(x);
    }
    
    int smallestValue(int n) {
        vector<int> pre(n + 1, 0);
        for(int i = 2; i <= n; i++){
            pre[i] = getFactorization(i);
        }
        
        int ans = INT_MAX;
        map<int, int> mp;
        while(n > 1){
            ans = min(ans, pre[n]);
            n = pre[n];
            if(mp.count(n))
                break;
            mp[n]++;
        }
        
        return ans;
    }
};
