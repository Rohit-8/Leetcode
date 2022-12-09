class Solution {
public:
//     vector<vector<int>> dp;
    
//     int res(vector<int> &a, int i, int j){
//         if(i == j) return a[i];
//         if(i > j) return 0;
        
//         if(dp[i][j] != -1) return dp[i][j];
//         int sum = 0;
//         sum = a[i] + min(res(a, i+2, j), res(a, i + 1, j-1));
//         sum = max(sum, a[j] + min(res(a, i+1, j-1), res(a, i, j-2)));
        
//         return dp[i][j] = sum;
//     }
    
    bool stoneGame(vector<int>& a) {
//         dp.resize(a.size() + 1, vector<int> (a.size() + 1, -1));
        
//         int sum = 0;
//         for(int i = 0; i < a.size(); i++)
//             sum += a[i];
            
//         return res(a, 0, a.size() - 1) > sum/2;
        
        //////// method 2 ///////
        
        // Since we have even number of piles, Alice can pick such that she takes all even indexed piles or all odd indexed piles. And since the sum of all piles is odd, Alice always wins.
        // hence return true;
        return true;
        
        
        ////// method 3 ///////
    }
};