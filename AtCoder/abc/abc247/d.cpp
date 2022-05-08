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

    deque<pair<ll, ll>> dq;
    while(q--){
        int p;
        cin >> p;

        if(p == 1){
            ll x, c;
            cin >> x >> c;
            if(!dq.empty()){
                if(dq.back().first == x){
                    dq.back().second += c;
                }
                else{
                    dq.push_back({x, c});
                }
            }
            else{
                dq.push_back({x, c});
            }
        }

        if(p == 2){
            ll c;
            cin >> c;

            ll sm = 0;
            while(1){
                if(dq.front().second >= c){
                    dq.front().second -= c;
                    sm += dq.front().first * c;
                    break;
                }
                else{
                    sm += dq.front().first * dq.front().second;
                    c -= dq.front().second;
                    dq.pop_front();
                }
            }

            cout << sm << "\n";
        }


    }

    return 0;
}