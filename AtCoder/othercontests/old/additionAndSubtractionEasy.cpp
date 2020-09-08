#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ll A, B;
    char op;

    cin >> A >> op >> B;

    if(op == '+') cout << A + B << endl;
    else cout << A - B << endl;
}