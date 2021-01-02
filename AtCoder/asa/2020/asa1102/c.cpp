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
    map<int, int> cnt;
    rep(i, n){
        int a;
        cin >> a;
        ++cnt[a];
    }

    vector<ll> use;
    for(auto k: cnt){
        if(k.second >= 2) use.push_back(k.first);
        if(k.second >= 4) use.push_back(k.first);
    }

    if(use.size() <= 1){
        cout << 0 << endl;
        return 0;
    }

    sort(use.begin(), use.end(), greater<int>());

    cout << use[0] * use[1] << endl;

    return 0;
}