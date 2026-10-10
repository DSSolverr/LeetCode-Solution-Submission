static const int _ = [](){ios_base::sync_with_stdio(false);cin.tie(NULL);return 0;}();

class Solution {
public:
    int strongPasswordChecker(string password) {
        int n = password.size();
        bool hasLower = false, hasUpper = false, hasDigit = false;
        for (char c : password) {
            if (islower(c)) hasLower = true;
            else if (isupper(c)) hasUpper = true;
            else if (isdigit(c)) hasDigit = true;
        }
        int missingTypes = (!hasLower) + (!hasUpper) + (!hasDigit);

        if (n < 6) return max(6 - n, missingTypes);

        vector<int> repeats;
        int i = 2;
        while (i < n) {
            if (password[i] == password[i - 1] && password[i] == password[i - 2]) {
                int len = 2;
                while (i < n && password[i] == password[i - 1]) {
                    ++len;
                    ++i;
                }
                repeats.push_back(len);
            } else {
                ++i;
            }
        }

        if (n <= 20) {
            int replace = 0;
            for (int len : repeats) replace += len / 3;
            return max(replace, missingTypes);
        }

        int deleteCnt = n - 20;
        int d = deleteCnt;

        for (int j = 0; j < (int)repeats.size(); ++j) {
            if (d > 0 && repeats[j] % 3 == 0) {
                --repeats[j];
                --d;
            }
        }

        for (int j = 0; j < (int)repeats.size(); ++j) {
            if (d >= 2 && repeats[j] % 3 == 1) {
                repeats[j] -= 2;
                d -= 2;
            }
        }

        int totalReplace = 0;
        for (int len : repeats) totalReplace += len / 3;
        int savedBy3 = min(totalReplace, d / 3);
        totalReplace -= savedBy3;

        return deleteCnt + max(totalReplace, missingTypes);
    }
};