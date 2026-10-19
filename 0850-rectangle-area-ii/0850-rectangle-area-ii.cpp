class Solution {
public:
    int getId(int ele,vector<int>&arr){
        int id = lower_bound(arr.begin(),arr.end(),ele) - arr.begin();
        return id;
    }
    int rectangleArea(vector<vector<int>>& rectangles) {
        map<int,int>x,y;
        for(auto &i : rectangles){
            x[i[0]]++;
            x[i[2]]++;
            y[i[1]]++;
            y[i[3]]++;
        }
        vector<int>xc,yc;
        for(auto &i : x) xc.push_back(i.first);
        for(auto &i : y) yc.push_back(i.first);
        vector<vector<int>>taken(401,vector<int>(401,0));
        long long ans = 0;
        for(auto &v : rectangles){
            for(int i = getId(v[0],xc);i<getId(v[2],xc);i++){
                for(int j = getId(v[1],yc);j<getId(v[3],yc);j++){
                    long long len = xc[i+1] - xc[i];
                    long long breath = yc[j+1] - yc[j];
                    if(taken[i][j]) continue;
                    taken[i][j] = true;
                    ans+=(long long)((len%1000000007)*(breath%1000000007))%1000000007;
                    ans%=1000000007;
                }
            }
        }
        return ans;
    }
};