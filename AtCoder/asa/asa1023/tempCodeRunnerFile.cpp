#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<int> cnt(13, 0);
    vector<int> d;
    int mn = 12;
    rep(i, n){
        int d_;
        cin >> d_;
        ++cnt[d_];
        if(cnt[d_]<= 2){
            if(d_==0 || (d_==12 && cnt[d_] == 2)){
                cout << 0 << endl;
                return 0;
            }

            d.push_back(d_);
        }

        mn = min(mn, d_);
    }

    n = d.size();

    if(n>=22){
        cout << 1 << endl;
        return 0;
    }

    vector<int> flip;
    vector<int> dd;
    int res = 0;
    rep(i, (1<<n)){
        flip.assign(n, 0);
        rep(j, n){
            if(i & (1<<j)){
                flip[j] = 1;
            }
        }

        dd.clear();
        dd.push_back(0);
        rep(j, n){
            if(flip[j]) dd.push_back(24-d[j]);
            else dd.push_back(d[j]);
        }

        sort(dd.begin(), dd.end());
        int mn_ = mn;
        rep1(j, n){
            mn_ = min(mn_, abs(dd[j]-dd[j-1]));
        }


        res = max(res, mn_);

    }

    cout << res << endl;

    return 0;
}