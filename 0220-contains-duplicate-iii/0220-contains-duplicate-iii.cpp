class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
        int n = nums.size();
        int j=0;
        set<int>st;
        for(int i=0;i<n;i++){
            if(i-j > indexDiff){
                st.erase(nums[j]);
                j++;

            }
            auto it = st.lower_bound(nums[i] - valueDiff);
            if(it!=st.end() && *it<=nums[i]+valueDiff) return true;
            st.insert(nums[i]);
        }
        return false;
    }
};