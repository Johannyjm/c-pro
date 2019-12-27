#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll lucas(ll n){
    if(n == 0) return 2;
    if(n == 1) return 1;

    return lucas(n-1) + lucas(n-2);
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    ll n;
    cin >> n;

    cout << lucas(n) << endl;

}