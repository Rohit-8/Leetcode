class Solution {
public:
    void dfs(vector<int> &nums, int i, int end, int k, int sum, vector<vector<int>> &sums) {
        if (i == end || k >= nums.size() / 4)
            sums[k].push_back(sum);
        else {
            dfs(nums, i + 1, end, k, sum, sums);
            dfs(nums, i + 1, end, k + 1, sum + nums[i], sums);
        }
    }
    
    int minimumDifference(vector<int>& nums) {
        int n = nums.size() / 2, n2 = n / 2, res = INT_MAX;
        
        int sum1 = accumulate(begin(nums), begin(nums) + n, 0), sum2 = accumulate(begin(nums) + n, end(nums), 0);
        vector<vector<int>> s1(n2 + 1), s2(n2 + 1);
        dfs(nums, 0, n, 0, 0, s1);
        dfs(nums, n, 2 * n, 0, 0, s2);
        
        for (int k = 0; k <= n2; ++k) {
            sort(begin(s2[k]), end(s2[k]));
            
            for (int s1k : s1[k]) {
                int comp = (sum1 + sum2) / 2 - (sum1 - s1k), diff = sum1 - sum2 - s1k * 2;
                int j = lower_bound(begin(s2[k]), end(s2[k]), comp) - begin(s2[k]);
                
                if (j < s2[k].size())
                    res = min(res, abs(diff + s2[k][j] * 2));
                
                if (j > 0)
                    res = min(res, abs(diff + s2[k][j - 1] * 2));
            }
        }
        return res;
    }
};