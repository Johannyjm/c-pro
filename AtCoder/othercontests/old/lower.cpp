#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    ll h[n];
    for (int i = 0; i < n; ++i) cin >> h[i];

    ll prev = h[0];
    int res = 0;
    int cnt = 0;

    for (int i = 1; i < n; ++i){

        if(prev >= h[i]){
            cnt++;
            res = max(cnt, res);
        }
        else{
            cnt = 0;
        }
        prev = h[i];
    }
    cout << res << endl;
}