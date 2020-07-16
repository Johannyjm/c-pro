#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;


int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ll n, k;
    cin >> n >> k;
    
    string s;
    cin >> s;
    
    vector<pair<char, int>> cnt;
    cnt.push_back(make_pair(s[0], 1));
    for(int i = 1; i < n; ++i){
        if(s[i] == cnt.back().first) ++cnt.back().second;
        else cnt.push_back(make_pair(s[i], 1));
    }

    int range = k*2;
    if(cnt[0].first == '1') ++range;

    ll res = 0;
    rep(i, min((int)cnt.size(), range)){
        res += cnt[i].second;
    }
    if(cnt.size() <= range){
        cout << res << endl;
        return 0;
    }

    int l = 0;
    int r = range;
    ll cur = res;
    while(1){
        ll inc = cnt[r].second;
        ++r;
        if(r < cnt.size()){
            inc += cnt[r].second;
            ++r;
        }
        ll dec = cnt[l].second;
        ++l;
        if(cnt[l].first == '0'){
            dec += cnt[l].second;
            ++l;
        }

        cur = cur - dec + inc;

        res = max(res, cur);

        if(r >= cnt.size()) break;
    }

    cout << res << endl;

    return 0;
}
