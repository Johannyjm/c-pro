#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    while(1){
        int w, d;
        cin >> w >> d;
        if(w == 0) break;

        vector<int> h1(w), h2(d);
        int res = 0;
        int sm1 = 0;
        int sm2 = 0;
        rep(i, w){
            cin >> h1[i];
            sm1 += h1[i];
        }
        rep(i, d){
            cin >> h2[i];
            sm2 += h2[i];
        }

        if(sm1 < sm2) {
            swap(h1, h2); // h1 > h2
            swap(w, d);
        }

        map<int, int> mp;
        rep(i, w) ++mp[h1[i]];
        
        res = max(sm1, sm2);
        rep(i, d){
            if(mp[h2[i]] == 0) res += h2[i];
            else --mp[h2[i]];
        }

        cout << res << endl;

    }

    return 0;
}