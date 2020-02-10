#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;
const ll INF = 1LL << 60;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    string n;
    int k;
    cin >> n >> k;

    vector<ll> num(100, 0);
    num[3] = 1;
    for(int i = 4; i < 100; ++i){
        num[i] = num[i-1] + i-2;
    }

    int three;
    int cnt = 0;
    rep(i, n.size()){
        if(n[i]!='0')++cnt;
        if(cnt==3)three = n[i] - '0';
    }

    ll res = 0;
    if(k==1){
        res += 9 * (n.size()-1) + (n[0]-'0');
    }

    if(k==2){
        ll base = 10*(n[0]-'0') + (n[1]-'0');
        ll d = n.size();
        res += (base-10-(n[0]-'0'-1)) * (d-1);
        res += (9-(n[1]-'0'))*(d-2);

        --d;
        while(d>=2){
            res += 81*(d-1);
            --d;
        }
    }

    if(k==3){
        ll d = n.size();
        res += 81 * num[d-1]*((n[0]-'0')-1);
        res += 81 * num[d-2];
        res += 9 * (d-4);
        res += three;
        --d;
        while(d>=3){
            res += 729*num[d];
            --d;
        }
    }

    cout << res << endl;

    return 0;
}