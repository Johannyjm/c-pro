#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    } else {
        return gcd(b, a % b);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, G;
    cin >> N >> G;

    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    int gcd_all = A[0];
    for (int i = 1; i < N; ++i) {
        gcd_all = gcd(gcd_all, A[i]);
    }

    if (gcd_all == G) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}