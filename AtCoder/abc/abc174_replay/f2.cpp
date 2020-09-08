#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

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

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, q;
    cin >> n >> q;

    vector<int> a(n);
    vector<int> li(n+1, -1);
    vector<vector<int>> ps(n);
    for(int i = 0; i < n; ++i){
        cin >> a[i];
        int l = li[a[i]];
        if(l != -1) ps[i].push_back(l);
        li[a[i]] = i;
    }

    vector<vector<pair<int, int>>> qs(n);
    for(int i = 0; i < q; ++i){
        int l, r;
        cin >> l >> r;
        --l;
        --r;
        qs[r].push_back(make_pair(l, i));
    }
    
    vector<int> res(q);
    for(int i = 0; i < n; ++i){
        for(int pl: ps[i]){
            add(pl+1, 1);
        }

        for(pair<int, int> p: qs[i]){
            int ql = p.first;
            int sub = get_sum(ql+1, n+1);

            int qi = p.second;
            res[qi] = (i - ql + 1) - sub;
        }
    }

    for(int i = 0; i < q; ++i) cout << res[i] << endl;

}
