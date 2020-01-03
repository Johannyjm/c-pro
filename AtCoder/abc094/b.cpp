#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, m, x;
    cin >> n >> m >> x;

    int road[n+1] = {0};
    rep(i, m) {
        int a;
        cin >> a;
        road[a-1] = 1;
    }
    
    int l = 0;
    int r = 0;

    rep(i, n+1){
        if(i<x) l += road[i];
        else r += road[i];
    }
    cout << min(l, r) << endl;

}