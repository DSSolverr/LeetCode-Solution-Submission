class Solution {
private:
    vector<vector<int>> dp;

    bool checkSquareful(const int& sumVal){
        int root = sqrt(sumVal);
        return (sumVal) == (root * root);
    }
    int solve(const vector<int>& nums, int mask, int prevIdx){
        int n = nums.size();
        if((mask + 1) == (1 << n)) return 1;

        if(dp[mask][prevIdx + 1] != -1) return dp[mask][prevIdx + 1];

        int ans = 0;

        // unordered_set<int> used;

        for(int i=0; i<n; i++){
            if(mask & (1 << i)) continue;

            // Skip duplicate elements if the previous identical element has not been used yet.
            if( (i > 0) && (nums[i] == nums[i-1]) && !(mask & (1 << (i-1))) ) continue;

            // if(used.contains(nums[i])) continue;
            // used.insert(nums[i]);

            if((prevIdx == -1) || checkSquareful(nums[i] + nums[prevIdx])){
                ans = ans + solve(nums, (mask | (1 << i)), i);
            }
        }

        return dp[mask][prevIdx + 1] = ans;
    }
public:
    int numSquarefulPerms(vector<int>& nums) {
        int n = nums.size();

        sort(nums.begin(), nums.end());

        dp.assign((1 << n) + 1, vector<int>(n + 1, -1) );

        return solve(nums, 0, -1);
    }
};