class Solution {
public:
    int minSetSize(vector<int>& a) {
        int n = a.size();
        
        priority_queue<int> pq;
        unordered_map<int,int> m;
        for(int i = 0; i < n; i++){
            m[a[i]]++;
        }
        
        for(auto x : m)
            pq.push(x.second);
        
        n = (n + 1)/2;
        int sum = 0;
        int ans = 0;
        while(!pq.empty()){
            ans ++;
            sum += pq.top();
            pq.pop();
            if(sum >= n) break;
        }
        cout<<n<<" sfs " << sum;
        
        return ans;
    }
};