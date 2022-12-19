class Solution {
public:
    vector<int> cycleLengthQueries(int n, vector<vector<int>>& q) {
        vector<int> ans;
        for(int i = 0; i < q.size(); i++){
            int a = q[i][0], b = q[i][1];
            int c = 0;
            
            while(a != b){
                if(b > a) b /= 2;
                else a /= 2;
                c ++;
            }
            ans.push_back(c + 1);
        }
        
        return ans;
    }
};