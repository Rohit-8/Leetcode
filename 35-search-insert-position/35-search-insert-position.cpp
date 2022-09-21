class Solution {
public:
    int searchInsert(vector<int>& a, int t) {
        int x = lower_bound(a.begin(), a.end(), t) - a.begin();
        return x;
    }
};