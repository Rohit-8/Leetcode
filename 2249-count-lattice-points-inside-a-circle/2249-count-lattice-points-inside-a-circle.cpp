class Solution {
public:
    int countLatticePoints(vector<vector<int>>& c) {
        int ans = 0;
        for(int i = 0; i <= 200; i++){
            for(int j = 0; j <= 200; j++){
                for(int k = 0; k < c.size(); k++){
                    if(sqrt((i - c[k][0]) * (i - c[k][0]) + (j - c[k][1]) * (j - c[k][1])) <= c[k][2])
                    {
                        ans ++;
                        break;
                    }
                }
            }
        }
        
        return ans;
    }
};