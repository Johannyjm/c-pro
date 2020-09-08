#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

pair<int, int> digit_sum(ll n){
    if(n < 10) return make_pair(n, 0);
    if(n == 10) return make_pair(1, 1);

    int ret = 0;
    int d = 0;
    while(n){
        d += n%10;
        n/=10;
        ++ret;
    }
    --ret;

    if(d < 10) return make_pair(d, ret);
    
    pair<int, int> p = digit_sum(d);
    
    return make_pair(p.first, p.second+ret);

}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    pair<int, int> pp = digit_sum(229);
    cout << pp.first << " " << pp.second << endl;

    return 0;

    int m;
    cin >> m;
    vector<ll> d(m), c(m);
    vector<ll> mul(m);
    int res = 0;
    rep(i, m){
        cin >> d[i] >> c[i];
        mul[i] = d[i] * c[i];
        res += c[i] - 1;
    }

    int nxt = 0;
    rep(i, m){
        pair<int, int> p = digit_sum(mul[i]);
        nxt += p.first;
        res += p.second;
    }

    pair<int, int> p2 = digit_sum(nxt);
    res += p2.second;

    cout << res << endl;

    return 0;
}