#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;

int main() {
    ll N, M, D;
    cin >> N >> M >> D;
    vector<ll> A(N), B(M);
    for (ll& a : A) cin >> a;
    for (ll& b : B) cin >> b;
    sort(A.begin(), A.end(), greater<ll>());
    sort(B.begin(), B.end(), greater<ll>());

    ll max_value = -1;
    int i = 0, j = 0;
    while (i < N && j < M) {
        cout << i << " " << j << " " << A[i] << " " << B[j] << endl;
        if (abs(A[i] - B[j]) <= D) {
            max_value = max(max_value, A[i] + B[j]);
            ++i;
            ++j;
        } else if (A[i] > B[j]) {
            ++j;
        } else {
            ++i;
        }
    }

    cout << max_value << endl;

    return 0;
}