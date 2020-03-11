#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;
const ll INF = 1LL << 60;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ll n;
    cin >> n;
    vector<ll> a(n), b(n);

    ll a_sum = 0;
    ll b_sum = 0;
    rep(i, n){
        ll tmp;
        cin >> tmp;
        a[i] = tmp;
        a_sum += tmp;
    }
    
    rep(i, n){
        ll tmp;
        cin >> tmp;
        b[i] = tmp;
        b_sum += tmp;
    }

    if(a_sum < b_sum){
        cout << -1 << endl;
        return 0;
    }

    ll same_cnt = 0;
    ll greater_cnt = 0;
    vector<ll> resource(n, -1);
    vector<ll> lack(n, -1);
    rep(i, n){
        if(a[i] >= b[i]){
            if(a[i] == b[i]) {
                ++same_cnt;
                resource[i] = 0;
            }
            else{
                resource[i] = a[i] - b[i];
                ++greater_cnt;
            }
        }
        else{
            lack[i] = b[i] - a[i];
        }
    }

    sort(resource.begin(), resource.end(), greater<ll>());
    sort(lack.begin(), lack.end(), greater<ll>());

    ll res = n - same_cnt - greater_cnt + 1;
    ll ptr = 0;
    rep(i, resource.size()){
        ll current = resource[i];
        while(ptr != lack.size()){
            if(current >= lack[ptr]){
                current -= lack[ptr];
                ++ptr;
            }
            else{
                lack[ptr] -= current;
                break;
            }
        }

        if(ptr == lack.size()) break;
        else ++res;
    }
    if(n == same_cnt+greater_cnt) cout << 0 << endl;
    else cout << res << endl;
    
    return 0;
}