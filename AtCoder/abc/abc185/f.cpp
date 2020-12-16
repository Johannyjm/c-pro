#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

const int MAX_N = 330000;
int n;
int bit[MAX_N];
void add(int pos, int x){
    ++pos;

    while(pos < MAX_N){
        bit[pos] ^= x;
        pos += pos & -pos;
    }
}

int get(int pos){
    ++pos;
    int ret = 0;
    while(pos > 0){
        ret ^= bit[pos];
        pos -= pos & -pos;
    }
    return ret;
}

int seg_get(int l, int r){
    return get(r) ^ get(l-1);
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int q;
    cin >> n >> q;
    rep(i, n){
        int a;
        cin >> a;
        add(i+1, a);
    }

    rep(_, q){
        int t, x, y;
        cin >> t >> x >> y;

        if(t == 1) add(x, y);
        else cout << seg_get(x, y) << endl;
    }

    return 0;
}