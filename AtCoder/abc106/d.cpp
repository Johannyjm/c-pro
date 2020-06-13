#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, m, q;
    cin >> n >> m >> q;
    
    vector<int> l(m), r(m);
    rep(i, m){
        cin >> l[i] >> r[i];
        --l[i];
        --r[i];
    }

    vector<int> sm(n, 0);
    int closed = 0;
    rep(i, m){
        if(l[i] == 0) ++sm[0];
        if(r[i] == 0) ++closed;
    }

    rep1(i, n){
        sm[i] = sm[i-1] - closed;
        closed = 0;
        rep(j, m){
            if(l[j] == i) ++sm[i];
            if(r[j] == i) ++closed;
        }
    }

    rep(i, n) cout << sm[i] << " ";
    cout << endl;

    rep(_, q){
        int a, b;
        cin >> a >> b;
        --a;
        --b;

        cout << abs(sm[b] - sm[a]) << "\n";
    }

    return 0;
}