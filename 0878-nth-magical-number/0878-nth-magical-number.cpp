class Solution {
public:

const int MOD = 1e9 + 7;


// Function to compute the greatest common divisor (GCD) of two numbers
int gcd(int x, int y) {
    while (y != 0) {
        int temp = y;
        y = x % y;
        x = temp;
    }
    return x;
}

// Function to compute the least common multiple (LCM) of two numbers
int lcm(int x, int y) {
    return (1LL * x * y) / gcd(x, y);
}

// Function to find the Nth magical number
int nthMagicalNumber(int n, int a, int b) {
    int L = lcm(a, b);
    long long int low = 0, high = 1e14;
    long long result = 0;

    while (low < high) {
        long long mid = low + (high - low) / 2;
        long long count = mid / a + mid / b - mid / L;

        if (count < n) {
            low = mid + 1;
        } else {
            high = mid;
        }
    }

    result = low % MOD;
    return result;
}
};