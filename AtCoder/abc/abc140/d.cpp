#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    vector<pair<char, int>> cnt;
    cnt.push_back(make_pair(s[0], 1));
    rep1(i, n){
        if(s[i] == cnt.back().first) ++cnt.back().second;
        else cnt.push_back(make_pair(s[i], 1));
    }

    // rep(i, cnt.size()) cout << cnt[i].first << " " << cnt[i].second << endl;
    if(cnt.size() <= k+1){
        cout << n-1 << endl;
        return 0;
    }
    int res = 0;
    int l_1 = 0;
    int l_2 = 0;
    int r_1 = 0;
    int r_2 = 0;
    rep(i, cnt.size()){
        res += cnt[i].second - 1;
        if(i==0 || i==cnt.size()-1){
            if(cnt[i].first == 'L') ++l_1;
            else ++r_1;
        }
        else{
            if(cnt[i].first == 'L') ++l_2;
            else ++r_2;
        }
    }

    int inc2r = min(k, r_2);
    int inc1r = k-inc2r;
    int inc2l = min(k, l_2);
    int inc1l = k-inc2l;
    
    cout << max(res+2*inc2r+inc1r, res+2*inc2l+inc1l) << endl;

    return 0;
}