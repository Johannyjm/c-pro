#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;
const ll INF = 1LL << 60;

// range sum query
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



// range add query
#define SEG_LEN (1 << 18)

int seg[SEG_LEN * 2];

// one point
long long int get(int ind){
    ind += SEG_LEN;
    long long int sum = 0;
    sum += seg[ind];
    while(true){
        ind /= 2;
        if(ind == 0)break;
        sum += seg[ind];
    }
    return sum;
}

// range
void add(int l, int r, int x){
    l += SEG_LEN;
    r += SEG_LEN;
    while(l < r){
        if(l % 2 == 1){
            seg[l] += x;
            l++;
        }
        l /= 2;
        if(r % 2 == 1){
            seg[r-1] += x;
            r--;
        }
        r /= 2;
    }
}

int main(){
    int n, q, com, ind, v, l, r;
    cin >> n >> q;
    for(int i = 0;i < q;i++){
        cin >> com;
        if(com == 0){//add
            cin >> l >> r >> v;
            add(l, r+1, v);
        }
        if(com == 1){//get
            cin >> ind;
            cout << get(ind) << endl;
        }
    }
    return 0;
}