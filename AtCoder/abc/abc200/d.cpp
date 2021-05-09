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
    vector<int> a;
    rep(i, n){
        int a_;
        cin >> a_;
        if(i < 8) a.push_back(a_%200);
    }

    n = min(n, 8);
    vector<vector<int>> cnt(200);
    rep(i, 1<<n){
        int s = 0;
        vector<int> b;
        rep(j, n){
            if(i & (1<<j)){
                b.push_back(j);
                s += a[j];
            }
        }

        if(cnt[s%200].size() > 0){
            cout << "Yes" << endl;
            cout << cnt[s%200].size() << " ";
            for(auto e: cnt[s%200]) cout << e+1 << " ";
            cout << endl;
            cout << b.size() << " ";
            for(auto e: b) cout << e+1 << " ";
            cout << endl;
            return 0;
        }
        else cnt[s%200] = b;
    }

    cout << "No" << endl;

    return 0;
}