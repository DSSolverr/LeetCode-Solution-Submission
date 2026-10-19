class Solution {
public:
    bool xorGame(vector<int>& nums) {
        int n=nums.size();
        if(n%2==0)
        return true;    

        int x=nums[0];
        for(int i=1;i<n;i++)
        x=(x^nums[i]);

        if(x==0)
        return true;
        return false;
    }
};