#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;
const ll INF = 1LL << 60;

const ll SEG_LEN = 1LL << 20;
int seg[SEG_LEN * 2] = {0};

void add(int idx, int x){
    idx += SEG_LEN;
    seg[idx] += x;
    while(1){
        idx /= 2;
        if(idx==0) break;
        seg[idx] = seg[idx*2] + seg[idx*2+1];
    }
}

int get_sum(int l, int r){
    l += SEG_LEN;
    r += SEG_LEN;
    int ret = 0;

    while(l<r){
        if(l%2){
            ret += seg[l];
            ++l;
        }
        l /= 2;

        if(r%2){
            ret += seg[r-1];
            --r;
        }
        r /= 2;
    }
    return ret;
}


int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, q, com, l, r, idx, x;
    cin >> n >> q;

    rep(i, q){
        cin >> com;

        if(com){
            cin >> l >> r;
            cout << get_sum(l, r+1) << endl;
        }
        else {
            cin >> idx >> x;
            add(idx, x);
        }
    }

    return 0;
}