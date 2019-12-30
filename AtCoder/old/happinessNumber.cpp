#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ll X, Y;
    cin >> X >> Y;

    ll res = X * Y;

    for(ll n = 1; n <= X; ++n){
        ll num = n * Y;

        if(num % X == 0 and num < res){
            res = num;
            break;
        }
    }
    cout << res << endl;

}