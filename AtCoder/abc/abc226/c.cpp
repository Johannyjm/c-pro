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
    vector<ll> t(n), k(n);
    vector<vector<ll>> a(n);
    rep(i, n){
        cin >> t[i] >> k[i];
        vector<ll> aa(k[i]);
        rep(j, k[i]){
            cin >> aa[j];
            --aa[j];
        }
        a[i] = aa;
    }
    
    ll res = t[n-1];
    queue<int> q;
    q.push(n-1);

    unordered_set<int> learned;
    learned.insert(n-1);

    while(!q.empty()){
        int v = q.front();
        q.pop();

        for(int nv: a[v]){
            if(learned.count(nv)) continue;

            res += t[nv];
            learned.insert(nv);
            q.push(nv);
        }
    }

    cout << res << endl;


    return 0;
}