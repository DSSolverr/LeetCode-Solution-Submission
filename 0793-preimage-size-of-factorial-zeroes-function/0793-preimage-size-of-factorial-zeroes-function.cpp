class Solution {
public:
    long long  powof5(long long x){
    long long n = 5 ;
    long long  ans = 0 ;
    while((x/n)>0){
        ans += (x/n);
        n *= 5;
    }
    return ans ;
   }
    int preimageSizeFZF(int k) {
        long long low = 0 , high = 5LL *(k+1) , mid ;
        long long  idx1 = -1 , idx2 = -1 ;
        // first ocurrance when it 
        while(low<=high){
            mid = low+ (high-low)/2;
            int pow10 =  powof5(mid);
            if(pow10 >= k){
                idx1 = mid ;
                high = mid -1 ;
                
            }
            else low = mid +1 ;
        }
        idx1 = low ;
        low = 0 , high = 5LL * (k + 1); ;
         while(low<=high){
            mid = low+ (high-low)/2;
            int pow10 =  powof5(mid);
            if(pow10 <= k){
                idx2 = mid ;
                low = mid +1 ;
            }
            else   high = mid -1 ; 
        }
    
        return (idx2-idx1+1) ;
    }
};