class Solution {
public:
    vector<int> numMovesStones(int a, int b, int c) {
        int mn = min({a, b, c});
        int mx = max({a, b, c});
        int y = mx - mn - 2;
        if(y == 0)
            return {0, 0};
        if(abs(a-b) < 3 or abs(b-c) < 3 or abs(c-a) < 3)
            return {1, y};
        
        return {2, y};
    }
};