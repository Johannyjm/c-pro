#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    ll a, b, x;
    cin >> a >> b >> x;

    cout << (b - a) / x + (a % x == 0 or b % x == 0) << endl;
}