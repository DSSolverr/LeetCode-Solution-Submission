class Solution {
public:
    int minMergedInteger(vector<int>& nums) {
        int ans = INT_MAX;

        for (int i = 0; i < nums.size(); i += 2) {
            int x = nums[i], y = nums[i + 1];
            int temp = y;

            while (temp > 0) {
                x *= 10;
                temp /= 10;
            }

            ans = min(ans, x + y);
        }

        return ans;
    }
};