#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, m, x, y;
    cin >> n >> m >> x >> y;

    vector<int> a(n), b(m);
    rep(i, n) cin >> a[i];
    rep(i, m) cin >> b[i];

    int now = 0;
    int inA = 1;  // 1: A, 0: B
    int res = 0;
    while(1){
        if(inA){
            int idx = lower_bound(a.begin(), a.end(), now) - a.begin();
            // cout << idx << endl;
            if(idx == n) break;
            int nxt = a[idx];
            now = nxt + x;
        }
        else{
            int idx = lower_bound(b.begin(), b.end(), now) - b.begin();
            // cout << idx << endl;
            if(idx == m) break;
            int nxt =  b[idx];
            now = nxt + y;
            ++res;
        }

        inA = 1 - inA;
    }

    cout << res << endl;

    return 0;
}