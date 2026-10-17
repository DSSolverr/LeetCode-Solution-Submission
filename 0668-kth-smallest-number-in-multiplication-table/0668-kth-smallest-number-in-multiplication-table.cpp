class Solution {
public:
    long long helperFunction(long long mid,long long m,long long n)
    {
        long long cnt = 0;
        for(int i = 1 ; i<=m ;i++)
        {
            cnt += min(n, mid / i);
        }
        return cnt;
    }

    int findKthNumber(int m, int n, int k) {
        long long low = 1;
        long long high = m*n;

        while(low<=high)
        {
            long long mid = low + (high-low)/2;

            long long cnt = helperFunction(mid,m,n);

            if(cnt>=k)
            {
                high = mid-1;
            }
            else
            {
                low = mid+1;
            }
        }

        return low;
    }
};