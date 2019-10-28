#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false); 
    int N;
    cin >> N;
    ll a[3 * N];

    for(int i = 0; i < 3 * N; ++i) cin >> a[i];
    sort(a, a + 3 * N, greater<int>());

    ll res = 0;
    for(int i = 1; i < 2 * N; i += 2) res += a[i];

    cout << res << endl;
}