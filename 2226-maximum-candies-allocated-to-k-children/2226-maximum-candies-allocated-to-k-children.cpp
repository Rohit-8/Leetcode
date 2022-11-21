class Solution {
public:
    bool res(vector<int> &a, long long p, long long k){
        long long sum = 0;
        for(int i = 0; i < a.size(); i++){
            sum += ((a[i] / p) * 1ll);
        }
        return sum >= k;
    }
    
    int maximumCandies(vector<int>& a, long long k) {
        long long sum = 0;
        for(int i = 0; i < a.size(); i++){
            sum += a[i]*1ll;
        }
        if(sum < k) return 0;
        
        long long l = 1, r = sum, ans = 0;
        while(l <= r){
            long long mid = (l + r) / 2;
            if(res(a, mid, k)){
                l = mid + 1;
                ans = mid;
            }
            else r = mid - 1;
        }
        
        return ans;
    }
};