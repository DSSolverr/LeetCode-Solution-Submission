class Solution {
public:
    int countStaircase(vector<int>& nums) {
        int mx = 1; 
        int n = nums.size(); 
        while(mx * (mx + 1) <= 2 * n) mx++; // this gives us maximum distinct freq which are possible for a number 
        int limit = *max_element(nums.begin(), nums.end()); 
        vector<int> freq(limit + 1, 0), reqFreq(limit + 1, 0); 
        int ans = 0;  

        for(int i = 0; i < n; i++) {
            int dis = 0;
            int matched = 0; 
            int processed = 0; 
            for(int j = i; j < n; j++) {
                int x= nums[j]; 
                if(freq[x] == 0) {
                    dis++; // new encountered 
                    if(dis > mx) break; // early exit 
                    reqFreq[x] = dis; 
                }
                freq[x]++; 
                processed = j; // processed till here. 
                if(freq[x] > reqFreq[x]) break; // early exit - not possible  
                if(freq[x] == reqFreq[x]) matched++; 
                if(matched == dis) ans++; // no of disticnt equal no of ele whose freq matches req 
            }
            // reset from i ... processed 
            for(int j = i; j <= processed; j++) {
                freq[nums[j]] = 0; 
            }
        }
        return ans; 
    }
};