#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;
const ll INF = 1LL << 60;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ll n;
    cin >> n;

    if(n%2 || n==0){
        cout << 0 << endl;
        return 0;
    }

    n /= 2;
    ll most = 1;
    while(most <= n){
        most *= 5;
    }

    most /= 5;

    ll res = 0;
    while(most != 1){
        // cout << n/most << " " << n << " " << most << endl;
        res += n/most;
        most /= 5;
    }

    cout << res << endl;

    return 0;
}