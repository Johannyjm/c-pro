#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int x, n;
    cin >> x >> n;

    vector<int> p(n);
    rep(i, n) cin >> p[i];

    sort(p.begin(), p.end(), greater<int>());
    int res = -1;
    int min_diff = 1001001001;
    rep(i, 201){
        bool flg = false;
        rep(j, n){
            if(i==p[j]){
                flg = true;
                break;
            }
        }
        if(flg) continue;
        int diff = abs(x - i);
        if(diff < min_diff){
            res = i;
            min_diff = diff;
        }
    }

    cout << res << endl;

    return 0;
}