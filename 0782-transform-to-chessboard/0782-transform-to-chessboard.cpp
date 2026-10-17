class Solution {
public:
    int movesToChessboard(vector<vector<int>>& board) {
        int N = board.size(); // The size of the board (N x N)

        // Count the frequency of each unique row in the board
        unordered_map<int, int> count;
        for (const auto& row : board) {
            int code = 0;
            for (int x : row) {
                code = (code << 1) + x; // Construct binary representation of the row
            }
            count[code]++;
        }

        int k1 = analyzeCount(count, N);
        if (k1 == -1) return -1;

        // Count the frequency of each unique column in the board
        count.clear();
        for (int c = 0; c < N; ++c) {
            int code = 0;
            for (int r = 0; r < N; ++r) {
                code = (code << 1) + board[r][c]; // Construct binary representation of the column
            }
            count[code]++;
        }

        int k2 = analyzeCount(count, N);
        return k2 >= 0 ? k1 + k2 : -1;
    }

private:
    int analyzeCount(unordered_map<int, int>& count, int N) {
        // If the map doesn't contain exactly 2 different keys, it's invalid
        if (count.size() != 2) return -1;

        auto it = count.begin();
        int k1 = it->first, v1 = it->second;
        ++it;
        int k2 = it->first, v2 = it->second;

        // Check if the counts of the two keys are valid
        if (!((v1 == N / 2 && v2 == (N + 1) / 2) || (v2 == N / 2 && v1 == (N + 1) / 2))) {
            return -1;
        }

        // Check if the two keys are bitwise opposites (XOR == all 1s)
        if ((k1 ^ k2) != (1 << N) - 1) return -1;

        // Calculate the number of swaps needed
        int mask = (1 << N) - 1; // N bits set to 1
        int ones = __builtin_popcount(k1 & mask); // Count the number of 1s in k1
        int cand = INT_MAX;

        // Check swaps for "zero start" and "ones start"
        if (N % 2 == 0 || ones * 2 < N) { // "Zero start"
            cand = min(cand, __builtin_popcount(k1 ^ 0xAAAAAAAA & mask) / 2);
        }
        if (N % 2 == 0 || ones * 2 > N) { // "Ones start"
            cand = min(cand, __builtin_popcount(k1 ^ 0x55555555 & mask) / 2);
        }

        return cand;
    }
};