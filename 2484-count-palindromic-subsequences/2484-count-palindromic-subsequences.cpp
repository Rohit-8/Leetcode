class Solution {
public:
    int pre[10000][10][10], suf[10000][10][10], cnts[10] = {};
int countPalindromes(string s) {
        int mod = 1e9 + 7, n = s.size(), ans = 0;
        for (int i = 0; i < n; i++) {
            int c = s[i] - '0';
            if (i) {
                for (int j = 0; j < 10; j++)
                    for (int k = 0; k < 10; k++) {
                        pre[i][j][k] = pre[i - 1][j][k];
                        if (k == c) pre[i][j][k] += cnts[j];
                    }
            }
            cnts[c]++;
        }
        memset(cnts, 0, sizeof(cnts));
        for (int i = n - 1; i >= 0; i--) {
            int c = s[i] - '0';
            if (i < n - 1)
                for (int j = 0; j < 10; j++)
                    for (int k = 0; k < 10; k++) {
                        suf[i][j][k] = suf[i + 1][j][k];
                        if (k == c) suf[i][j][k] += cnts[j];
                    }
            cnts[c]++;
        }
        for (int i = 2; i < n - 2; i++)
            for (int j = 0; j < 10; j++)
                for (int k = 0; k < 10; k++)
                    ans = (ans + (long long)pre[i - 1][j][k] * suf[i + 1][j][k]) % mod;
        return ans;
    }
};