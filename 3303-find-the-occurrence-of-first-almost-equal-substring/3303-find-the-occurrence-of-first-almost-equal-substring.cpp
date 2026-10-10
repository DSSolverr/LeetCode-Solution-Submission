static const int _ = [](){ios_base::sync_with_stdio(false);cin.tie(NULL);return 0;}();

class Solution {
    vector<int> computeZ(const string& s) {
        int n = s.size();
        vector<int> z(n, 0);
        int l = 0, r = 0;
        for (int i = 1; i < n; ++i) {
            if (i <= r) z[i] = min(r - i + 1, z[i - l]);
            while (i + z[i] < n && s[z[i]] == s[i + z[i]]) ++z[i];
            if (i + z[i] - 1 > r) {
                l = i;
                r = i + z[i] - 1;
            }
        }
        return z;
    }

public:
    int minStartingIndex(string s, string pattern) {
        int n = s.size(), m = pattern.size();
        if (m > n) return -1;

        string s1 = pattern + "#" + s;
        vector<int> z1 = computeZ(s1);

        string revPattern = pattern;
        reverse(revPattern.begin(), revPattern.end());
        string revS = s;
        reverse(revS.begin(), revS.end());
        string s2 = revPattern + "#" + revS;
        vector<int> z2 = computeZ(s2);

        for (int i = 0; i <= n - m; ++i) {
            int lcp = min(z1[m + 1 + i], m);
            int revIdx = n - m - i;
            int lcs = min(z2[m + 1 + revIdx], m);
            if (lcp + lcs >= m - 1) return i;
        }
        return -1;
    }
};