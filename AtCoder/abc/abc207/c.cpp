#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

vector<ll> t, l, r;
bool overlapped(int i, int j){
    if(t[i] == 1 || t[i] == 2){
        if(t[j] == 1 || t[j] == 3){
            if(r[j] < l[i]) return false;
        }
        if(t[j] == 2 || t[j] == 4){
            if(r[j] <= l[i]) return false;
        }
    }
    if(t[i] == 3 || t[i] == 4){
        if(r[j] <= l[i]) return false;
    }

    if(t[i] == 1 || t[i] == 3){
        if(t[j] == 1 || t[j] == 2){
            if(r[i] < l[j]) return false;
        }
        if(t[j] == 3 || t[j] == 4){
            if(r[i] <= l[j]) return false;
        }
    }
    if(t[i] == 2 || t[i] == 4){
        if(r[i] <= l[j]) return false;
    }

    return true;
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    t.resize(n);
    l.resize(n);
    r.resize(n);
    rep(i, n) cin >> t[i] >> l[i] >> r[i];

    int res = 0;
    rep(i, n){
        rep(j, i){
            if(overlapped(i, j)) ++res;
        }
    }

    cout << res << endl;

    return 0;
}