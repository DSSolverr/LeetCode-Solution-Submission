class Solution {
public:
    long long leastOpsExpressTarget(long long x, long long target,long long Less =1 ,long long  Operations =0) {
        while(Less*x<target)
        Less*=x , Operations++;
        return min({Less!=1?Operations + leastOpsExpressTarget(x,target-Less):INT_MAX,(Less*x<2*target)? Operations + leastOpsExpressTarget(x,Less*x-target) + 1 :INT_MAX,2*target-1});
    }
};