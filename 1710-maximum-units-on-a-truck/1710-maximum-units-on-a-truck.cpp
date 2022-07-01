class Solution {
public:
    
    static bool cmp(vector<int> &a, vector<int> &b){
        return a[1] > b[1];
    }
    
    int maximumUnits(vector<vector<int>>& a, int t) {
        sort(a.begin(), a.end(), cmp);
        int sum = 0;
        
        for(int i = 0;i< a.size(); i++){
            if(t<=0) break;
            sum += a[i][1] * min(a[i][0], t);
            t -= min(a[i][0], t);
        }
        
        return sum;
    }
};