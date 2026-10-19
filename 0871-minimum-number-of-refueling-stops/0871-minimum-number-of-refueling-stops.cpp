class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int n=stations.size();
        int MaxLimit=startFuel; 
        int i=0,ans=0;
        priority_queue<int> Q;
        while(1){
            if(MaxLimit>=target)return ans;
            while(i<n && stations[i][0]<=MaxLimit){
                Q.push(stations[i][1]);
                i++;
            }
            if(!Q.empty()){
                MaxLimit+=Q.top();
                Q.pop();
            }
            else
                return -1;
            ans++;
        }
        return ans;
    }
};