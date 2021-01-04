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
    vector<int> a(n), b(n);
    rep(i, n) cin >> a[i] >> b[i];

    sort(a.begin(), a.end());
    sort(b.begin(), b.end(), greater<int>());
    int idx = (n-1)/2;
    int l = a[idx] + ((n%2==1)? 0: a[idx+1]);
    int r = b[idx] + ((n%2==1)? 0: b[idx+1]);
    cout << l << " " << r << endl;
    cout << r-l+1 << endl;

    return 0;
}