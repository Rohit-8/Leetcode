class Solution {
public:
    int hardestWorker(int n, vector<vector<int>>& logs) {
        int a = logs.size();
        int b = logs[0].size();
        int id = logs[0][0];
        
        int mini  = logs[0][1];
        for(int i = 1; i < a; i++){
            int ans = logs[i][1] - logs[i-1][1];
            if(ans>mini){
                mini = ans;
                id = logs[i][0];
            }
            else if(ans == mini){
                id = min(id, logs[i][0]);
            }
        }
        return id;
    }
};