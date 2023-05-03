#include <iostream>
#include <vector>

using namespace std;

const int MOD = 998244353;

int main() {
    int N;
    cin >> N;

    vector<int> dp(N + 1);
    dp[1] = 1;

    for (int i = 2; i <= N; i++) {
        for (int j = 1; j <= 6; j++) {
            if (i % j == 0) {
                dp[i] = (dp[i] + dp[i / j]) % MOD;
            }
        }
    }

    int numerator = dp[N];
    int denominator = 1;

    for (int i = 0; i < N; i++) {
        denominator = (denominator * 6) % MOD;
    }

    int inverse_denominator = 1;
    int power = MOD - 2;

    while (power > 0) {
        if (power % 2 == 1) {
            inverse_denominator = (inverse_denominator * denominator) % MOD;
        }

        denominator = (denominator * denominator) % MOD;
        power /= 2;
    }

    int answer = (numerator * inverse_denominator) % MOD;
    cout << answer << endl;

    return 0;
}