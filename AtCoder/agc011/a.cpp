#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;
const ll INF = 1LL << 60;
 
int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
 
    ll n, c, k;
    cin >> n >> c >> k;
    map<ll, ll> t;
    rep(i, n) {
        ll T;
        cin >> T;
        ++t[T];
    }
 
    ll res = 0;
    ll left = 0;
    ll current = 0;
    for(auto itr = t.begin(); itr != t.end(); ++itr){
        ll time = itr->first;
        ll num = itr->second;
        if(left == 0){
            res += num / c;
            current += num % c;
            if(current) left = time;
            else left = 0;
        }
        else{
            if(time - left <= k){
                current += num;
                if(current/c) {
                    res += current / c;
                    current %= c;
                    if(current) left = time;
                    else left = 0;
                }
            }
            else{
                ++res;
 
                res += num / c;
                current = num % c;
                if(current) left = time;
                else left = 0;
            }
        }
    }
 
    if(current) res += (current + c - 1) / c;
 
    cout << res << endl;
    
 
    return 0;
}