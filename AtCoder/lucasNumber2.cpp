#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ll n;
    cin >> n;

    ll prevprev = 2; //l0
    ll prev = 1; //l1

    if (n == 1){
        cout << prev << endl;
        return 0;
    }

    ll res = prevprev + prev;
    for (int i = 2; i < n; ++i){
        prevprev = prev;
        prev = res;
        res = prevprev + prev;
    }
    cout << res << endl;

}