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

    int res = 0;
    rep(i, cnt.size()) res += cnt[i].second - 1;

    cout << min(n-1, res + 2*k) << endl;

    return 0;
}