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
    vector<int> cnt(110000, 0);

    int res = 0;
    rep(i, n){
        int a;
        cin >> a;
        ++cnt[a];
        if(cnt[a] > 1) ++res;
    }


    cout << res << endl;

    return 0;
}