class Solution {
public:
    static bool cmp(vector<int> &a, vector<int> &b){
        if(a[1] != b[1]) return a[1] < b[1];
        return a[0] < b[0];
    }
    int findLongestChain(vector<vector<int>>& a) {
        sort(a.begin(), a.end(), cmp);
        
        int ans = 1, prev = a[0][1];
        for(int i = 1; i < a.size(); i++){
            if(a[i][0] > prev) ans ++, prev = a[i][1];
        }
        
        return ans;
    }
};