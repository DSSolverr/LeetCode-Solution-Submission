class dsu {
    public:
        vector <int> parent , Rank;
        dsu(int n) {
            parent.resize(n + 1);
            Rank.resize(n + 1 , 1);
            iota(parent.begin() , parent.end() , 0);
        }
        int find(int x) {
            if (parent[x] == x) {
                return x;
            }
            return parent[x] = find(parent[x]);
        }
        
        void unite(int x , int y) {
             x = find(x);
             y = find(y);
             if (x != y) {
                if (Rank[x] < Rank[y]) {
                    swap(x , y);
                }
                parent[y] = x;
                Rank[x] += Rank[y];
             }
        }
};
class Solution {
public:
    int largestComponentSize(vector<int>& a) {
        int ans = count(a.begin() , a.end() , 1);
        int n = int(a.size());
        dsu d(n);
        unordered_map <int , int> M;
        for (int i = 0; i < n; i++) {
            if (a[i] == 1) {
                continue;
            }
            for (int j = 2; j * j <= a[i]; j++) {
                if (a[i] % j == 0) {
                    if (M.count(j)) {
                        d.unite(i , M[j]);
                    } else {
                        M[j] = i;
                    }
                    while (a[i] % j == 0) {
                        a[i] /= j;
                    }
                }
            }
            if (a[i] > 1) {
                if (M.count(a[i])) {
                    d.unite(i , M[a[i]]);
                } else {
                    M[a[i]] = i;
                }
            }
        }
        for (int i = 0; i < n; i++) {
             int s = d.find(i);
             ans = max(ans , d.Rank[s]);

        }
        return ans;
    }
};