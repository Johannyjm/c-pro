#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    vector<int> cnt(m+1, 0);
    rep(i, n){
        int a;
        cin >> a;
        ++cnt[a];
    }

    int mx = 0;
    int idx = -1;
    rep(i, m+1){
        if(mx < cnt[i]){
            mx = cnt[i];
            idx = i;
        }
    }

    if(mx <= n/2) cout << "?" << endl;
    else cout << idx << endl;
    
    return 0;
}