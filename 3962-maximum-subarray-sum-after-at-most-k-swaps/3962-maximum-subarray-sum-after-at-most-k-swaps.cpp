
#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
        long long INF = -1e15;
    long long maxSum(vector<int>& nums, int k) {

        int n=nums.size();
        long long ans=INF;

        int negs =0;
        for(int i : nums)if(i < 0)negs++;

        if(negs <= k && negs < n){
            ans =0;
            for(int i : nums)if(i>=0)ans += i;
            return ans;
        }

        if(negs == n){
            return *max_element(nums.begin(),nums.end());
        }

        if(k==0)
        {
            
            long long sum=0;
            for(int j=0;j<n;j++)
            {
                    int i = nums[j];
                    sum+=i;
                    ans=max(ans,sum);
                    sum = max(sum,0LL);
            }
            return ans;
        }

        int sum=0;
        vector<vector<int>> subarraySum(n+1,vector<int>(n+1)),arr1(n+1,vector<int>(n+1)),arr2(n+1,vector<int>(n+1));

    
        for(int i =0;i<n;i++){
            sum=0;
            for(int j=i;j<n;j++){
                sum += nums[j];
                subarraySum[i][j] = sum;
            }
        }

       
        for(int i =0 ;i<n;i++){
            priority_queue<int> pq;
            int sum=0;
            for(int j=i;j<n;j++){
                if(nums[j] <0){
                    if(pq.size() < k){
                        pq.push(nums[j]);
                        sum += nums[j];
                    }
                    else{
                        if(pq.top() > nums[j]){
                            sum -= pq.top(); pq.pop();
                            sum += nums[j];
                            pq.push(nums[j]);
                        }
                    }
                }
                arr1[i][j] = sum;
            }
        }

        for(int i= 0;i<n;i++){
            priority_queue<int,vector<int>,greater<int>> pq;
            int sum=0;
            for(int j=0 ;j<i;j++){
                if(nums[j] >0){
                    if(pq.size() < k){
                        pq.push(nums[j]);
                        sum += nums[j];
                    }
                    else{
                        if(pq.top() < nums[j]){
                            sum -= pq.top();
                            pq.pop();
                            pq.push(nums[j]);
                            sum += nums[j];
                        }
                    }
                }
            }
            arr2[i][n-1] = sum;
            for(int j = n-1;j>=i;j--){
                if(nums[j] >0){
                    if(pq.size() < k){
                        pq.push(nums[j]);
                        sum += nums[j];
                    }
                    else{
                        if(pq.top() < nums[j]){
                            sum -= pq.top();
                            pq.pop();
                            pq.push(nums[j]);
                            sum += nums[j];
                        }
                    }
                }
                if(j-1>=i)
                arr2[i][j-1] = sum;   
            }
        }

        for(int i =0;i<n;i++){
            for(int j=i;j<n;j++){
                long long tans = subarraySum[i][j] - arr1[i][j] + arr2[i][j];
                ans = max(ans,tans);
            }
        }
        return ans;
    }
};
