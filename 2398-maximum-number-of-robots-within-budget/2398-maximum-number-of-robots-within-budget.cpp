class Solution {
public:
    int n;
    long long res(vector<int> &ct, vector<int> &rc, long long k){
        if(k <= 0) return 0;
        long long ans = 1e18;
        long long i = 0, mx = 0, sum = 0;
        deque<long long> dq(k);
        for(i = 0; i < n and i < k; i++){
            while ((!dq.empty()) && ct[i] >= ct[dq.back()])
                dq.pop_back();
 
            dq.push_back(i);
            sum += rc[i];
        }
        mx = ct[dq.front()];
        
        for(int j = 0; i < n; i++, j ++){
            mx = ct[dq.front()];
            ans = min(ans, mx + k * sum);
            while ((!dq.empty()) && dq.front() <= i - k)
                dq.pop_front();
            
            while ((!dq.empty()) && ct[i] >= ct[dq.back()])
                dq.pop_back();
 
            dq.push_back(i);
            sum += rc[i];
            sum -= rc[j];
        }
        mx = ct[dq.front()];
        ans = min(ans, mx + k * sum);
        
        return ans;
    }
    int maximumRobots(vector<int>& ct, vector<int>& rc, long long b) {
        n = ct.size();
        
        long long l = 0, r = n;
        int ans = 0;
        while(l <= r){
            long long mid = l + (r-l)/2;
            
            if(res(ct, rc, mid) <= b){
                ans = mid;
                l = mid + 1;
            }
            else r = mid-1;
        }
        
        return ans;
    }
};