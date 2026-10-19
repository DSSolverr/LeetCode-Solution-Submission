class Solution {
public:
    int sumSubseqWidths(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        long long MOD = 1e9 + 7;
        int n = nums.size();
        
        // Precompute powers of 2
        vector<long long> pow2(n);
        pow2[0] = 1;
        for (int i = 1; i < n; i++) {
            pow2[i] = (pow2[i-1] * 2) % MOD;
        }
        
        long long result = 0;
        
        for (int i = 0; i < n; i++) {
            // nums[i] as maximum contributes: nums[i] * 2^i
            // nums[i] as minimum contributes: -nums[i] * 2^(n-1-i)
            long long contribution = (nums[i] * pow2[i]) % MOD;
            contribution = (contribution - nums[i] * pow2[n-1-i]) % MOD;
            result = (result + contribution) % MOD;
        }
        
        // Handle negative result from modulo
        result = (result + MOD) % MOD;
        
        return (int)result;
    }
};