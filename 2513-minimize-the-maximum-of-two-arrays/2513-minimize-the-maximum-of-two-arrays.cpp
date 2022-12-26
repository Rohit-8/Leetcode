class Solution {
public:
    int getMax(int cnt, long long d1, long long d2 = 1) {
        long long d = lcm(d1, d2);
        return cnt + cnt / (d - 1) - (cnt % (d - 1) ? 0 : 1);
    }
    
    int minimizeSet(int d1, int d2, int cnt1, int cnt2) {
        // return max({getMax(cnt1, d1), getMax(cnt2, d2), getMax(cnt1 + cnt2, d1, d2) });
        
        long long l = 0, r = 1e14;
        while(l <= r){
            long long mid = l + (r - l) / 2;
            long long a = mid / d1;
            long long b = mid / d2;
            long long c = mid / (lcm(1ll * d1, 1ll * d2));
            
            a = mid - a, b = mid - b, c = mid - c;
            if(cnt1 <= a and cnt2 <= b and cnt1 + cnt2 <= c)
                r = mid - 1;
            else l = mid + 1;
        }
        
        return l;
    }
};