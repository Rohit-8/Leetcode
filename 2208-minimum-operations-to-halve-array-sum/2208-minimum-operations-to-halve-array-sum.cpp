class Solution {
public:
    int halveArray(vector<int>& a) {
        priority_queue<double> pq;
        double sum = 0;
        double x = 0;
        for(int i = 0; i < a.size(); i++){
            sum += a[i];
            x += a[i];
            pq.push(a[i]);
        }
        if(x == 1) return 1;
        int ans = 0;
        while(!pq.empty()){
            double t = pq.top();
            pq.pop();
            t /= (2.0);
            sum -= t;
            ans ++;
            if(sum <= x / 2.0) break;
            pq.push(t);
        }
        
        return ans;
    }
};