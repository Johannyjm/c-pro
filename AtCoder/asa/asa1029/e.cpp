#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, m, Q;
    cin >> n >> m >> Q;
    vector<pair<int, int>> lr(m), pq(Q);
    rep(i, m){
        int l, r;
        cin >> l >> r;
        lr[i] = {l, r};
    }
    rep(i, Q){
        int p, q;
        cin >> p >> q;
        pq[i] = {p, q};
    }

    sort(lr.begin(), lr.end());
    sort(pq.begin(), pq.end());

    int lmx = 0;
    int res = n;
    rep(i, Q){
        int qf = pq[i].first;

        while(lr[lmx].first < qf){
            ++lmx;
            --res;
        }

        

    }
    



    return 0;
}