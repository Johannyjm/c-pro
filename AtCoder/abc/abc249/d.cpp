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
    
    map<ll, ll> count;
    ll a_max = 0;
    rep(i, n){
        ll a;
        cin >> a;
        ++count[a];
        a_max = max(a_max, a);
    }

    ll res = 0;
    for(auto key1 = count.begin(); key1 != count.end(); ++key1){ // Ai * Aj = Ak
        ll ai = key1->first;
        for(auto key2 = count.begin(); key2 != count.end(); ++key2){

            ll aj = key2->first;

            if(ai * aj > a_max) break;

            ll ak = ai * aj;

            res += count[ai] * count[aj] * count[ak];
        }
    }

    cout << res << endl;

    return 0;
}