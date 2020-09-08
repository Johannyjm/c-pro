#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;
const ll INF = 1LL << 60;

const ll SEG_LEN = 1LL << 20;
int seg[26][SEG_LEN * 2];


void add(int alpha, int idx, int x){
    idx += SEG_LEN;
    seg[alpha][idx] += x;
    while(1){
        idx /= 2;
        if(idx==0) break;
        seg[alpha][idx] = seg[alpha][idx*2] + seg[alpha][idx*2+1];
    }
}


int get_sum(int alpha, int l, int r){
    l += SEG_LEN;
    r += SEG_LEN;
    int ret = 0;

    while(l<r){
        if(l%2){
            ret += seg[alpha][l];
            ++l;
        }
        l /= 2;

        if(r%2){
            ret += seg[alpha][r-1];
            --r;
        }
        r /= 2;
    }
    return ret;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ll n, q;
    string s;

    cin >> n >> s >> q;

    rep(i, n){
        add(s[i] - 'a', i+1, 1);
    }

    rep(_, q){
        int cmd;
        cin >> cmd;

        if(cmd==1){
            int idx;
            char c;
            cin >> idx >> c;

            add(c - 'a', idx, 1);
            add(s[idx-1] - 'a', idx, -1);
            s[idx-1] = c;
        }
        else{
            int l, r;
            cin >> l >> r;

            int res = 0;
            rep(alpha, 26){
                if(get_sum(alpha, l, r+1)) ++res;
            }
            cout << res << endl;
        }
    }

    return 0;
}