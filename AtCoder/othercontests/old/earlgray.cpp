#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ll N;
    cin >> N;

    cout << N - 2 + (N + 1) * N / 2 << endl;
}