class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& q) {
        vector<int> ans;
        for(int k = 0; k < q.size(); k++){
            
            priority_queue<pair<string, int>> a;
            for(int i = 0; i < nums.size(); i++){
                
                string s = nums[i].substr(nums[i].size() - q[k][1]);
                if(a.size() < q[k][0])
                    a.push({s, i});
                else if(a.top().first > s){
                    a.pop();
                    a.push({s, i});
                }
            }
            
            ans.push_back(a.top().second);
        }
        
        return ans;
    }
};