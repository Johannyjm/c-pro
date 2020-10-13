#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

vector<ll> w, l, v;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ll n, m;
    cin >> n >> m;
    w.resize(n);
    ll mx_w = 0;
    ll sm_w = 0;
    rep(i, n){
        cin >> w[i];
        mx_w = max(mx_w, w[i]);
        sm_w += w[i];
    }

    l.resize(m);
    v.resize(m);
    ll mx_l = 0;
    vector<pair<ll, ll>> vl(m);
    rep(i, m){
        cin >> l[i] >> v[i];
        vl[i] = {v[i], l[i]};

        mx_l = max(mx_l, l[i]);

        if(v[i] < mx_w){
            cout << -1 << endl;
            return 0;
        }
    }

    sort(vl.begin(), vl.end());

    cout << endl;
    rep(i, m) cout << vl[i].second << " " << vl[i].first << endl;

    sort(w.begin(), w.end());
    ll res = 1001001001;
    do{
        rep(i, (1ll<<(n-1))){
            vector<int> sep;
            int s_cnt = 0;
            rep(j, n-1){
                if(i & (1<<j)){
                    sep.push_back(j);
                    ++s_cnt;
                }
            }
            
            vector<ll> grp(s_cnt+1);
            if(s_cnt == 0) grp[0] = sm_w;
            else{
                // cout << "a  ";
                // rep(j, (int)sep.size()) cout << sep[i] << " ";
                // cout << endl;
                int prev = 0;
                rep(j, s_cnt){
                    ll sm = 0;
                    for(int k = prev; k < sep[j]+1; ++k){
                        sm += w[k];
                    }
                    grp[j] = sm;

                    prev = sep[j];
                }
                ll sm = 0;
                for(int j = prev+1; j < n; ++j) sm += w[j];
                grp.back() = sm;
            }

            // cout << endl;
            // rep(j, (int)grp.size()) cout << grp[j] << " ";
            // cout << endl;

            
        }
    }while(next_permutation(w.begin(), w.end()));

    return 0;
}