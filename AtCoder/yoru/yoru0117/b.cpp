#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    vector<int> a(3);
    rep(i, 3) cin >> a[i];

    sort(a.begin(), a.end());

    cout << a[2] - a[0] << endl;

    return 0;
}