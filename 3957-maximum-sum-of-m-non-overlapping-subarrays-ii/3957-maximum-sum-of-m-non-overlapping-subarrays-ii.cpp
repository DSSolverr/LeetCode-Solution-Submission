class Solution {
    
    struct Node{
        long long s;
        int c;
    };

    Node solve(int n,int l,int r,long long p,vector<long long> &prev){
        vector<Node> dp(n+1,{0,0});
        deque<int> dq;

        for(int i=1;i<=n;i++){
            int j=i-l;

            if(j>=0){
                while(!dq.empty()){
                    int x=dq.back();

                    long long v1=dp[x].s-prev[x];
                    long long v2=dp[j].s-prev[j];

                    if(v2>v1 || (v2==v1 && dp[j].c <=dp[x].c)){
                        dq.pop_back();
                    }
                    else{
                        break;
                    }
                }

                dq.push_back(j);
            }

            while(!dq.empty() && dq.front() < i-r){
                dq.pop_front();
            }

            dp[i]=dp[i-1];

            if(!dq.empty()){
                int x=dq.front();

                long long ns=dp[x].s-prev[x]+prev[i]-p;
                int nc=dp[x].c+1;

                if(ns > dp[i].s || (ns==dp[i].s && nc < dp[i].c)){
                    dp[i]={ns,nc};
                }
            }
        }

        return dp[n];
    }

    long long helper(int n,int l,int r,vector<long long> &prev){
        long long ans=-(long long)4e18;
        deque<int> dq;

        for(int i=1;i<=n;i++){
            int j=i-l;

            if(j>=0){
                while(!dq.empty() &&prev[dq.back()]>=prev[j]){
                    dq.pop_back();
                }

                dq.push_back(j);
            }

            while(!dq.empty() && dq.front()<i-r){
                dq.pop_front();
            }

            if(!dq.empty()){
                ans=max(ans,prev[i]-prev[dq.front()]);
            }
        }

        return ans;
    }
public:
    long long maximumSum(vector<int>& nums, int m, int l, int r) {
        int n=nums.size();

        vector<long long> prev(n+1);

        for(int i=0;i<n;i++){
            prev[i+1]=prev[i]+nums[i];
        }

        Node curr=solve(n,l,r,0,prev);

        if(curr.c ==0){
            return helper(n,l,r,prev);
        }

        if(curr.c<=m){
            return curr.s;
        }

        long long low=0,high=2e11;
        long long ans=-1;

        while(low<=high){
            long long mid=low+(high-low)/2;

            Node x=solve(n,l,r,mid,prev);

            if(x.c <=m){
                ans=x.s+mid*m;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }

        return ans;
    }
};