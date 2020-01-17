#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    
    vector<ll> a(n);
    ll len_sum = 0;
    rep(i, n){
        ll len;
        cin >> len;
        len_sum += len;
        a[i] = len;
    }
    
    ll half_len = len_sum / 2;
    ll current = 0;
    ll left;
    ll right;
    rep(i, n){
        current += a[i];
        if(current >= half_len){
            right = current;
            left = current - a[i];
            break;
        }
    }

    cout << min(right - (len_sum - right), (len_sum - left) - left) << endl;

    return 0;
}