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

    int res = 0;
    for(auto k: cnt){

        if(k.first > k.second) res += k.second;
        if(k.first < k.second) res += (k.second-k.first);
    }

    cout << res << endl;

    return 0;
}