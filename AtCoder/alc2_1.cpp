#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int a, b, c;
    cin >> a >> b >> c;
    cout << max(0, c - max(0, a - b)) << endl;
}