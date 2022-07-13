class Solution {
public:
    int threeSumClosest(vector<int>& a, int t) {
        int n = a.size();
        
        sort(a.begin(), a.end());
        int ans = INT_MAX;
        int prev = INT_MAX;
        for(int i = 0; i < n - 2; i++){
            int j = i + 1, k = n-1;
            
            int sum = 0;
            while(j < k){
                sum = a[i] + a[j] + a[k];
                if(abs(sum-t) < prev){
                    prev = abs(sum-t);
                    ans = sum;
                }
                
                if(sum < t) j++;
                else if(sum > t) k--;
                else return sum;
            }
            
        }
        
        return ans;
    }
};