#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ll r, x, y;
    cin >> r >> x >> y;

    ll dist2 = x*x + y*y;

    if(r*r == dist2){
        cout << 1 << endl;
        return 0;
    }
    if(dist2 < r*r){
        cout << 2 << endl;
        return 0;
    }

    ll res = ceil(sqrt((double)dist2 / (double)(r*r)));

    cout << res << endl;


    return 0;
}