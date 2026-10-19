class Solution {
public:
    bool splitArraySameAverage(vector<int>& nums) {
        ranges::sort(nums, greater<>());
        int n = nums.size();

        vector<int> prefix(n + 1, 0);
        for (int i = 0; i < n; ++i)
            prefix[i + 1] = prefix[i] + nums[i];
        
        auto can_make = [&](auto& self, int k, int sum, int first) -> bool {
            if (k == 0)                                      // complete recursion
                return sum == 0;    
            if (sum < prefix[n] - prefix[n - k])             // prune sum < MIN
                return false; 
            for (int i = first; i <= n - k; ++i) { 
                if (sum > prefix[i + k] - prefix[i])         // prune sum > MAX
                    return false; 
                if (self(self, k - 1, sum - nums[i], i + 1)) // check recursively
                    return true;
            }
            return false;
        };

         for (int k = 1; k <= n / 2; ++k) 
            if (prefix[n] * k % n == 0) 
                if (can_make(can_make, k, prefix[n] * k / n, 0)) 
                    return true;
         
        return false;
    }
};