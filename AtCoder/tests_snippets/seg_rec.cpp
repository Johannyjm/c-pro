#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

vector<ll> seg(1ll << 20);
const int INF = (1ll<<31) - 1;

void set_value(ll pos, ll val){
    pos += 1ll << 19;
    seg[pos] = val;
    while((pos /= 2) > 0){
        seg[pos] = min(seg[pos * 2], seg[pos * 2 + 1]);
    }
}

ll get_min(int ql, int qr, int sl=0, int sr=1ll<<19, int pos=1){
    if(qr<=sl || sr<=ql) return INF;
    if(ql<=sl && sr<=qr) return seg[pos];
    
    ll sm = (sl+sr) / 2;
    ll lmin = get_min(ql, qr, sl, sm, pos*2);
    ll rmin = get_min(ql, qr, sm, sr, pos*2+1);

    return min(lmin, rmin);
}


int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ll n, q;
    cin >> n >> q;

    rep(i, n) set_value(i, INF); 

    rep(_, q){
        int com, x, y;
        cin >> com >> x >> y;

        if(com == 0){
            set_value(x, y);
        }

        else{
            cout << get_min(x, y+1) << endl;
        }
    }

    return 0;
}