class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        int a = INT_MAX;
        int b = INT_MAX;
        int c = 0;

        for(int i = 1; i <= n; i++) {
            int minCost = INT_MAX;

            minCost = min(minCost, c + 1 + costs[i - 1]);

            if(b != INT_MAX) {
                minCost = min(minCost, b + 4 + costs[i - 1]);
            }

            if(a != INT_MAX) {
                minCost = min(minCost, a + 9 + costs[i - 1]);
            }

            a = b;
            b = c;
            c = minCost;
        }

        return c;
    }
};