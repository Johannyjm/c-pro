#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, q;
    cin >> n >> q;
    vector<ll> a(n), b(n);
    rep(i, n) cin >> a[i] >> b[i];

    map<int, multiset<int>> mp;
    rep(i, n) mp[b[i]].insert(a[i]);

    multiset<int> maxs;
    for(auto itr = mp.begin(); itr != mp.end(); ++itr){
        maxs.insert(*itr->second.rbegin());
    }

    rep(_, q){
        int who, to;
        cin >> who >> to;
        --who;

        int from = b[who];
        int rate = a[who];

        // max moves
        if(*mp[from].rbegin() == rate){
            maxs.erase(maxs.find(rate));
            mp[from].erase(mp[from].find(rate));

            if(!mp[from].empty()) maxs.insert(*mp[from].rbegin());
        }
        // non-max erase
        else mp[from].erase(mp[from].find(rate));

        // empty moves
        if(mp[to].empty()) maxs.insert(rate);
        if(!mp[to].empty() && *mp[to].rbegin() < rate){
            maxs.erase(maxs.find(*mp[to].rbegin()));
            
            // insert
            maxs.insert(rate);
        }
        // insert
        mp[to].insert(rate);
        
        cout << *maxs.begin() << endl;

        b[who] = to;
    }

    return 0;
}