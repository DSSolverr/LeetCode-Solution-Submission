uint64_t A[100000];
uint8_t viz[100000];
class Solution {
public:
    static inline int digitSum(int x){
        int sum=0;
        for(; x>0; x/=10){
            sum+=x%10;
        }
        return sum;
    }
    static inline uint64_t pack ( int ds , int x , int i ) {
        return ((uint64_t)ds<<47ULL)+((uint64_t)x<<17ULL)+i ;
    }
    static int minSwaps(vector<int>& nums) {
        const int n=nums.size();
        for (int i=0; i<n; i++){
            int x=nums[i];
            A[i]=pack(digitSum(x), x, i);
        }
        sort(A, A+n);
        memset(viz, 0, n);
        int cnt=0, mask=(1<<17)-1;
        for(int i=0; i<n; i++){
            if (viz[i] || (A[i]&mask)==i) continue;
            int cycle=0;
            for(int j=i; !viz[j]; j=A[j]&mask){
                cycle++;
                viz[j]=1;
            }
            cnt+=(cycle-1);
        }
        return cnt;
    }
};
auto init = []()
{ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();