#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    map<int, pair<int, int>> mp;

    mp[0] = make_pair(1, 2);

    cout << mp[0].first << " " << mp[0].second << endl;
    cout << endl;

    cout << mp[1].first << " " << mp[1].second << endl;

    return 0;
}