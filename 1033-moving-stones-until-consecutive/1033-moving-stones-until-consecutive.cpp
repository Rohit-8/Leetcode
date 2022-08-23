class Solution {
public:
    vector<int> numMovesStones(int a, int b, int c) {
        auto [m, M] = minmax({abs(b-a), abs(c-b), abs(c-a)});
        return {(m > 2) + (M > m+1), M-2};
    }
};