class Solution {
public:
    int consecutiveNumbersSum(int n) {

        int k = 2;
        int count = 1;

        while(k * k < 2 * n) {

            int kx = n - k * (k - 1) / 2;

            if(kx % k == 0)
                count++;

            k++;
        }

        return count;
    }
};