#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    string s, t;
    cin >> s >> t;
    ll n = s.size();
    ll m = t.size();

    vector<vector<int>> cnt(26);
    rep(i, n){
        cnt[s[i] - 'a'].push_back(i);
    }

    rep(i, 26){
        sort(cnt[i].begin(), cnt[i].end());
    }

    // rep(i, 26){
    //     for(auto el: cnt[i]) cout << el << " ";
    //     cout << endl;
    // }

    rep(i, m){
        if(cnt[t[i] - 'a'].empty()){
            cout << -1 << endl;
            return 0;
        }
    }
    ll res = 0;
    int ptr = cnt[t[0] - 'a'].front();
    vector<int> a;
    rep1(i, m){
        a = cnt[t[i] - 'a'];
        if(a.back() <= ptr){
            res += n;
            ptr = a.front();
        }
        else{
            int idx = upper_bound(a.begin(), a.end(), ptr) - a.begin();
            ptr = a[idx];
        }
    }


    cout << res + ptr + 1 << endl;

    return 0;
}