#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ll m;
    cin >> m;
    deque<pair<ll, ll>> dq;
    vector<ll> d(m), c(m);
    rep(i, m){
        cin >> d[i] >> c[i];
        dq.push_back(make_pair(d[i], c[i]));
    }

    ll res = 0;
    while(1){
        pair<ll, ll> p = dq.front();

        ll sm = 0;
        if(p.second >= 2){
            if(p.second == 2) dq.pop_front();
            else dq.front().second -= 2;

            sm = p.first * 2;
        }
        else{
            if(p.second == 0) exit(1);
            sm += p.first;
            dq.pop_front();
            pair<ll, ll> p2 = dq.front();

            if(p2.second == 1) dq.pop_front();
            else --dq.front().second;

            sm += p2.first;
        }

        ll l = sm/10;
        ll r = sm%10;

        if(l == 0){
            if(r == dq.front().first) ++dq.front().second;
            else dq.push_front(make_pair(r, 1));
        }

        else{
            if(l == r){
                if(l == dq.front().first) dq.front().second += 2;
                else dq.push_front(make_pair(l, 2));
            }
            else{
                if(r == dq.front().first) ++dq.front().second;
                else{
                    dq.push_front(make_pair(r, 1));
                    dq.push_front(make_pair(l, 1));
                }
            }
        }

        ++res;

        if(dq.size() == 1) break;
    }

    cout << res << endl;

    return 0;
}