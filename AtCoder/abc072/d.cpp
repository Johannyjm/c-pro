#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<int> p(n);
    vector<bool> is_idx(n, false);
    rep(i, n) {
        int p;
        cin >> p;
        --p;
        if(i==p){
            is_idx[i] = true;
        }
    }

    int res = 0;
    int cnt = 0;
    rep(i, n){
        if(is_idx[i]) ++cnt;
        else{
            if(cnt){
                res += (cnt+1) / 2;
                cnt = 0;
            }
        }
    }
    if(cnt) res += (cnt+1) / 2;
    cout << res << endl;
}