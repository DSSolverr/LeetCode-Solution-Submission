class Solution {
public:
    long long minimumMaxValue(int n, int index, int value) {
        if(value == 1) return -1;
        int p = smallestPf(value);
        int left = value - p;
        int leftIdx = 2*index;
        if(index > 0 && left < leftIdx) return -1;
        
        int right = n - index - 1;
        if(right == 0) return value;

        return 2LL * (right - 1) + value + p;
    }
    int smallestPf(int x){
        if(x % 2 == 0) return 2;
        for(int i = 3; i * i <= x; i += 2){
            if(x % i == 0) return i;
        }
        return x;
    }
};