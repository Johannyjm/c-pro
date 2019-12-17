#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n, d;
    cin >> n >> d;
    int range = 2 * d + 1;

    cout << n/range + (n%range!=0) << endl;
}