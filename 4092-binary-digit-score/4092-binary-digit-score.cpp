class Solution {
    static constexpr int lut[7][7] = {
        {0, 0, 0, 0, 0, 0, 0},
        {0, 1, 2, 3, 4, 5, 6},
        {0, 2, 4, 1, 2, 2, 3},
        {0, 3, 6, 9, 1, 1, 2},
        {0, 4, 8, 12, 16, 1, 1},
        {0, 5, 10, 15, 20, 25, 1},
        {0, 6, 12, 18, 24, 30, 36}
    };

public:
    int calculateScore(int a, int b) {
        int u = __builtin_popcount(a);
        int v = __builtin_popcount(b);

        return lut[u][v];
    }
};