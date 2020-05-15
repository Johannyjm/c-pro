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
    rep(i, n){
        ll tmp;
        cin >> tmp;
        --tmp;
        a[i] = tmp;
    }

    map<ll, ll> seen;
    ++seen[0];
    ll curr = 0;
    ll nxt;
    vector<ll> lam;
    lam.push_back(0);
    ll back;
    int cnt = 1;

    if(k==1){
        cout << a[a[0]] + 1 << endl;
        return 0;
    }
    while(1){
        if(cnt == k){
            cout << curr << endl;
            return 0;
        }
        nxt = a[curr];
        lam.push_back(nxt);

        if(seen[nxt] == 0) {
            ++seen[nxt];
            curr = nxt;
        }
        else {
            back = nxt;
            break;
        }
        ++cnt;
    }

    ll head = 0;
    ll T = 1;
    bool flg = false;
    rep(i, lam.size()){
        if(lam[i] == back){
            head = i;
            for(int j = i + 1; j < lam.size(); ++j){
                if(lam[j] == back) {
                    flg = true;
                    break;
                }
                ++T;
            }
        }
        if(flg) break;
    }

    // cout << back << endl;
    // rep(i, lam.size()) cout << lam[i] << " ";
    // cout << endl;

    // cout << head << " " << T << endl;

    ll lm = head+T;

    if(k < lm) cout << lam[k] << endl;
    else {
        k -= lm;
        k = (k-1)%T;

        cout << a[lam[head + k]] + 1 << endl;
    }

    return 0;
}