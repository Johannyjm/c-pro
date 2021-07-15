#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ll a, b, c, d;
    cin >> a >> b >> c >> d;

    ll cyan = a;
    ll red = 0;
    int res = 0;
    while(cyan > d*red){
        cyan += b;
        red += c;
        ++res;

        if(res > 1000000){
            cout << -1 << endl;
            return 0;
        }
    }

    cout << res << endl;

    return 0;
}