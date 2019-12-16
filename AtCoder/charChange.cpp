#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    char c;
    cin >> c;

    cout << c - 0x20 << endl;

    char d = c - -0x20;

    cout << d << endl;
}