class Solution {
    int ans;

public:
    void solve(int i, int j, vector<vector<int>>& grid, int tot) {
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() ||
            grid[i][j] == -1) {
            return;
        }
        if (grid[i][j] == 2) {
            if (tot == 0) {
                ans++;
            }
            return;
        }
        int temp = grid[i][j];
        grid[i][j] = -1;
        solve(i + 1, j, grid, tot - (temp == 0));
        solve(i - 1, j, grid, tot - (temp == 0));
        solve(i, j + 1, grid, tot - (temp == 0));
        solve(i, j - 1, grid, tot - (temp == 0));
        grid[i][j] = temp;
    }

    int uniquePathsIII(vector<vector<int>>& grid) {
        ans = 0;
        int si = 0;
        int sj = 0;
        int tot = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1) {
                    si = i;
                    sj = j;
                } else if (grid[i][j] == 0) {
                    tot++;
                }
            }
        }
        solve(si, sj, grid, tot);
        return ans;
    }
};