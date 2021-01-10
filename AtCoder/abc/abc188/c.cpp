#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<pair<int, int>> a(1<<n);
    rep(i, 1<<n){
        int a_;
        cin >> a_;
        a[i] = {a_, i};
    }
    int now = 1<<n;
    rep(i, n-1){
        vector<pair<int, int>> nxt;
        for(int j = 0; j < now-1; j += 2){
            if(a[j].first > a[j+1].first) nxt.push_back(a[j]);
            else nxt.push_back(a[j+1]);
        }
        a = nxt;
        now /= 2;
    }

    if(a[0].first < a[1].first) cout << a[0].second+1 << endl;
    else cout << a[1].second+1 << endl;

    return 0;
}