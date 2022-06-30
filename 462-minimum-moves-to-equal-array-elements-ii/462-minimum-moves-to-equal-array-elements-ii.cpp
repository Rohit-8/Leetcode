class Solution {
public:
    int minMoves2(vector<int>& a) {
        sort(a.begin(), a.end());
        
        int sum = a[a.size()/2];
        
        long long ans = 0;
        for(int i = 0; i< a.size(); i++)
            ans += abs(sum-a[i]);
        
        return (int)ans;
    }
};