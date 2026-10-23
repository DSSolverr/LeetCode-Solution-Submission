class Solution {
public:
    vector<int> threeEqualParts(vector<int>& arr) {
        int n=arr.size(),ones=count(arr.begin(),arr.end(),1);
        if(ones==0) return {0,n-1}; // if full array is of zeros
        if(ones%3) return {-1,-1};

        ones=ones/3; // calculating the size of each block with equal ones.


        int curr_one=0,first=-1,second=-1,third=-1;
        for(int i=0;i<n;i++) {
            if(arr[i]==1) curr_one++;

            if(curr_one==1 and first==-1) first=i;
            else if(curr_one==ones+1 and second==-1) second=i;
            else if(curr_one==2*ones+1 and third==-1) third=i;
        }

        int i,j,k;
        for(i=first,j=second,k=third;k<n;i++,j++,k++) {
            if(not (arr[i]==arr[j] and arr[j]==arr[k])) return {-1,-1};
        }
        return {i-1,j};
    }
};