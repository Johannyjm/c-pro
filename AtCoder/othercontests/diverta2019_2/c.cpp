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
    vector<ll> a(n), ispos(n, 0);
    int neg = 0;
    ll absm = 0;
    ll abmn = 1001001001;
    rep(i, n){
        cin >> a[i];
        if(a[i] >= 0) ispos[i] = 1;
        else ++neg;
        absm += abs(a[i]);
        abmn = min(abmn, abs(a[i]));
    }

    ll m;
    vector<pair<int, int>> res;
    if(neg==0 || neg==n){
        if(n == 2){
            cout << max(a[0], a[1]) - min(a[0], a[1]) << endl;
            cout << max(a[0], a[1]) << " " <<  min(a[0], a[1]) << endl;
            return 0;
        }

        res.resize(n-1);
        m = absm - abmn*2;
        
        if(neg == 0) sort(a.begin(), a.end());
        else sort(a.begin(), a.end(), greater<int>());
        
        int now = 0;
        rep(i, n-1){
            if(i == 0){
                res[i] = {a[i], a[i+1]};
                now = a[i] - a[i+1];
            }
            else if(i == n-2){
                if(neg == 0) res[i] = {a[i+1], now};
                else res[i] = {now, a[i+1]};
            }

            else{
                res[i] = {now, a[i+1]};
                now -= a[i+1];
            }
        }
    }

    else{
        m = absm;
        sort(a.begin(), a.end());
        vector<int> negs, poss;
        for(auto e: a){
            if(e >= 0) poss.push_back(e);
            else negs.push_back(e);
        }
        int pos = n-neg;
        int now = negs.front();
        rep(i, pos-1){
            res.push_back({now, poss[i]});
            now -= poss[i];
        }
        negs.front() = now;

        now = poss.back();
        for(auto e: negs){
            res.push_back({now, e});
            now -= e;
        }
    }

    cout << m << endl;
    for(auto e: res) cout << e.first << " " << e.second << endl;



    return 0;
}