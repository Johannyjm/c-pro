#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, q;
    cin >> n >> q;

    vector<int> a(n);
    rep(i, n) cin >> a[i];

    sort(a.begin(), a.end());

    while(q--){
        int x;
        cin >> x;

        auto itr = lower_bound(a.begin(), a.end(), x);

        cout << n - int(itr - a.begin()) << "\n";
    }

    return 0;
}