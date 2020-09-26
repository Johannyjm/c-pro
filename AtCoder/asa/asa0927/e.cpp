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
    vector<ll> a(n);
    rep(i, n) cin >> a[i];

    deque<pair<ll, ll>> cmp; // 0: white, 1: black
    rep(i, n){
        if(i%2 == 0) cmp.push_back({0, a[i]});
        else cmp.push_back({1, a[i]});
    }

    ll res = 0;
    int isblack = 1;
    rep(_, n){
        if(cmp.front().first == isblack && cmp.back().first == isblack) break;

        if(cmp.front().first == cmp.back().first){
            if(cmp.front().second < cmp.back().second){
                res += cmp.front().second;
                cmp.front().first = isblack;
            }
            else{
                res += cmp.back().second;
                cmp.back().first = isblack;
            }
        }
        else{
            if(cmp.front().first == isblack){
                res += cmp.back().second;
                cmp.back().first = isblack;
            }
            else{
                res += cmp.front().second;
                cmp.front().first = isblack;
            }
        }

        if(cmp.size() == 1) break;

        if(cmp[0].first == cmp[1].first){
            cmp[1].second += cmp[0].second;
            cmp.pop_front();
        }
        else{
            cmp[cmp.size() - 2].second += cmp[cmp.size()-1].second;
            cmp.pop_back();
        }

        isblack = 1-isblack;
    }

    cout << res << endl;


    return 0;
}