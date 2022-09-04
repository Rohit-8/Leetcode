class Solution {
public:
    int maximumRobots(vector<int>& times, vector<int>& costs, long long budget) {
        long long i = 0, j, sum = 0, n = times.size();
        multiset<int> s;
        for (int j = 0; j < n; ++j) {
            sum += costs[j];
            s.insert(times[j]);
            if (*rbegin(s) + sum * (j - i + 1) > budget) {
                sum -= costs[i];
                s.erase(s.find(times[i++]));
            }
        }
        return n - i;
    }
};