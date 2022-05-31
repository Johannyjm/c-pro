#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int q;
    cin >> q;

    map<int, int> mp;

    rep(_, q){
        int cmd;
        cin >> cmd;

        if(cmd == 1){
            int x;
            cin >> x;

            ++mp[x];
        }

        if(cmd == 2){
            int x, c;
            cin >> x >> c;

            mp[x] = max(0, mp[x]-c);
        }

        if(cmd == 3){

            auto mx = mp.rbegin();
            auto mn = mp.begin();
            while(mx->second == 0) ++mx;
            while(mn->second == 0) ++mn;
            // cout << endl;
            // cout << mp.rbegin()->first << " " <<  mp.begin()->first << endl;
            cout << mx->first - mn->first << endl;
            // cout << endl;
        }

        // for(auto k: mp){
        //     cout << k.first << ":" << k.second << ", ";
        // }
        // cout << endl;
    }

    return 0;
}