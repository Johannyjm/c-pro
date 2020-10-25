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
    int mn = 12;
    rep(i, n){
        int d_;
        cin >> d_;
        ++cnt[d_];
        if(cnt[d_] >= 3 || (d_==12&&cnt[d_]>=2) || d_==0){
            cout << 0 << endl;
            return 0;
        }

        mn = min(mn, d_);
    }


    vector<int> d, fix;
    rep(i, 13){
        if(cnt[i] == 1) d.push_back(i);
        if(cnt[i] == 2){
            fix.push_back(i);
            fix.push_back(24-i);
        }
    }

    n = d.size();
    if(n==0){
        sort(fix.begin(), fix.end());
        int ans = mn;
        rep1(j, (int)fix.size()){
            ans = min(ans, abs(fix[j]-fix[j-1]));
        }
        cout << ans << endl;
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

        dd = fix;
        dd.push_back(0);
        rep(j, n){
            if(flip[j]) dd.push_back(24-d[j]);
            else dd.push_back(d[j]);
        }

        sort(dd.begin(), dd.end());
        int mn_ = mn;
        rep1(j, (int)dd.size()){
            mn_ = min(mn_, abs(dd[j]-dd[j-1]));
        }


        res = max(res, mn_);

    }

    cout << res << endl;

    return 0;
}