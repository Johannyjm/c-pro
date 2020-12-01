#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, a;
    cin >> n >> a;
    vector<int> x(n);
    rep(i, n) cin >> x[i];

    int res = 0;
    rep1(i, 1<<n){
        vector<int> use(n, 0);
        int cnt = 0;
        rep(j, n){
            if(i & (1<<j)){
                use[j] = 1;
                ++cnt;
            }
        }

        int sm = 0;
        rep(j, n){
            if(use[j]) sm += x[j];
        }

        if(sm%cnt == 0 && sm/cnt == a){
            ++res;
            cout << sm << " " << cnt << endl;
        }
    }

    cout << res << endl;

    return 0;
}