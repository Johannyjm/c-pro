#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ll n, k;
    cin >> n >> k;

    vector<ll> a(n);
    rep(i, n) {
        cin >> a[i];
        --a[i];
    }

    vector<ll> journey;
    int prev = 0;
    rep(i, 2*n+1000) {
        int curr = a[prev];
        if(i == k-1){
            cout << curr+1 << endl;
            return 0;
        }
        journey.push_back(curr);
        prev = curr;
    }
    // rep(i, 20) cout << journey[i] << " ";
    // cout << endl;

    ll loop_end = journey[n];
    ll loop_start = n-1;
    while(journey[loop_start] != loop_end){
        --loop_start;
    }

    ll period = n - loop_start;

    k %= period;

    while(k < n) k += period;

    cout << a[journey[k-2]]+1 << endl;



    return 0;
}