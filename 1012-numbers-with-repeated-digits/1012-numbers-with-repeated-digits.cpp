class Solution {
public:
    int dp[11][2][2][1024][2];

    int solve(string &s, int idx, bool tight,
              bool rep, int mask, bool lz) {

        if (idx == s.size())
            return rep;

        if (dp[idx][tight][rep][mask][lz] != -1)
            return dp[idx][tight][rep][mask][lz];

        int up = tight ? s[idx] - '0' : 9;
        int res = 0;

        for (int dig = 0; dig <= up; dig++) {

            if (dig == 0 && lz) {

                res += solve(
                    s,
                    idx + 1,
                    tight && (dig == up),
                    0,
                    mask,
                    1
                );

            } else {

                int isDigitUsed = (mask >> dig) & 1;

                res += solve(
                    s,
                    idx + 1,
                    tight && (dig == up),
                    rep || isDigitUsed,
                    mask | (1 << dig),
                    0
                );
            }
        }

        return dp[idx][tight][rep][mask][lz] = res;
    }

    int numDupDigitsAtMostN(int n) {

        memset(dp, -1, sizeof(dp));

        string s = to_string(n);

        return solve(s, 0, 1, 0, 0, 1);
    }
};