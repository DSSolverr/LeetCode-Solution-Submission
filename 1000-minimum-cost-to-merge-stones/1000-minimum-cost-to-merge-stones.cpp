class Solution {
public:
    const long long INF = 1e18;
    long long dp[31][31][31];
    long long solve(int l, int r, int piles, int k, vector<int>& pre) {
        // means if single element left and piles ==1 then mincost=0 otherwise
        // it is impossible to do that ...
        if(piles<0 || l>=30 || r>=30) return INF;
        
        if (l == r) {
            return (piles == 1) ? 0 : INF;
        }
        if (dp[l][r][piles] != -1)
            return dp[l][r][piles];
        long long ans = INF;
        for (int i = l; i < r; i += (k - 1)) {
            long long left = solve(l, i, 1, k, pre);// other cases like 1,2,3 handle itself in 1 for future call//
            long long right = solve(i + 1, r, piles - 1, k, pre);// here we build piles -1 so take make required piles//
            if (left != INF && right != INF) {
                ans = min(ans, left + right);
            }
        }
       // when there is one pile required means this is made of another k piles so we have to call for that accordingly//
        if (piles == 1) {
            long long cost = solve(l, r, k, k, pre);
            ans = min(ans, pre[r + 1] - pre[l] + cost);
        }

        return dp[l][r][piles] = ans;
    }

    int mergeStones(vector<int>& stones, int k) {
        int n = stones.size();
        vector<int> pre(n + 1);
        pre[0] = 0;
        for (int i = 1; i <= n; i++) {
            pre[i] = pre[i - 1] + stones[i - 1];
        }
        memset(dp, -1, sizeof(dp));
        long long ans = solve(0, n - 1, 1, k, pre);
        return (ans == INF) ? -1 : (int)ans;
    }
};