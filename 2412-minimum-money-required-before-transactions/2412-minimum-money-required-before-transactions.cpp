class Solution {
public:
    long long minimumMoney(vector<vector<int>>& ts) {
        long long spend = 0, cashback = 0, cost = 0;
        for (auto &t : ts) {
            if (t[0] > t[1]) {
                spend += t[0] - t[1];
                cashback = max(cashback, (long long)t[1]);
            }
            else
                cost = max(cost, (long long)t[0]);
        }
        return spend + max(cashback, cost);
    } 
};