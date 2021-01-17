#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];

    sort(a.begin(), a.end(), greater<int>());

    ll res = a.front();
    int ptr = 0;
    rep(i, n-2){
        ptr = i/2;
        res += a[ptr+1];
        // cout << ptr << " " << a[ptr] << endl;
    }

    cout << res << endl;

    return 0;
}