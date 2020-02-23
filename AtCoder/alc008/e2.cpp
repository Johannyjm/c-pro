#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;
const ll INF = 1LL << 60;

ll three_base(ll num){
    ll ret = 0;
    ll d = 1;
    while(num){
        ret += num%4 * d;
        num /= 4;
        d *= 10;
    }

    return ret;
}

pair<ll, bool> convert_753(ll num){
    ll ret_first = 0;
    ll d = 1;
    bool three = false;
    bool five = false;
    bool seven = false;
    bool flg = true;
    while(num){
        ll n = num%10;
        if(n==1) {
            ret_first += 3*d;
            three = true;
        }
        else if(n==2) {
            ret_first += 5*d;
            five = true;
        }
        else if(n==3) {
            ret_first += 7*d;
            seven = true;
        }
        else flg = false;
        
        num /= 10;
        d *= 10;
    }

    pair<ll, bool> ret = make_pair(ret_first, (three && five && seven && flg));

    return ret;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ll n;
    cin >> n;

    ll res = 0;
    ll base = 0;
    while(1){
        ll threed = three_base(base);
        pair<ll, bool> converted = convert_753(threed);

        if(converted.first>n) break;
        if(converted.second) ++res;
        // cout << converted.first << " " << converted.second << endl;
        ++base;
    }

    cout << res << endl;


    return 0;
}