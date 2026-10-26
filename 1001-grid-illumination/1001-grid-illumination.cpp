class Solution {
public:
    vector<int> gridIllumination(int n, vector<vector<int>>& lamps,
                                 vector<vector<int>>& queries) {
        set<pair<int, int>> st;
        unordered_map<int, int> row, col, diag1, diag2;

        for (auto& it : lamps) {
            if (st.find({it[0], it[1]}) == st.end()) {
                int r = it[0], c = it[1];
                row[r]++;
                col[c]++;
                diag1[r + c]++;
                diag2[c - r + n - 1]++;
            }

            st.insert({it[0], it[1]});
        }

        int dx[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
        int dy[8] = {-1, 0, 1, 1, 1, 0, -1, -1};

        int m = queries.size();
        vector<int> res(m, 0);

        for (int i = 0; i < m; i++) {
            int r = queries[i][0], c = queries[i][1];

            if (row[r] or col[c] or diag1[r + c] or diag2[c - r + n - 1]) {
                res[i] = 1;
            }

            if (st.find({r, c}) != st.end()) {
                st.erase({r, c});
                row[r]--;
                col[c]--;
                diag1[r + c]--;
                diag2[c - r + n - 1]--;
            }

            for (int j = 0; j < 8; j++) {
                int nr = r + dx[j], nc = c + dy[j];

                if (nr >= 0 and nr < n and nc >= 0 and nc < n and
                    st.find({nr, nc}) != st.end()) {
                    st.erase({nr, nc});
                    row[nr]--;
                    col[nc]--;
                    diag1[nr + nc]--;
                    diag2[nc - nr + n - 1]--;

                    if(row[nr]==0) row.erase(nr);
                    if(col[nc]==0) col.erase(nc);
                    if(diag1[nr+nc]==0) diag1.erase(nr+nc);
                    if(diag2[nc-nr+n-1]==0) diag2.erase(nc-nr+n-1);
                }
            }
        }

        return res;
    }
};