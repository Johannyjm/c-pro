#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

// range set query
const ll SEG_LEN = 1LL << 20;
//int seg[SEG_LEN * 2] = {0};
vector<pair<int, set<int>>> seg;


void add(int idx, int x){
    idx += SEG_LEN;
    seg[idx].second.insert(x);
    set<int> temp_set;
    while(1){
        idx /= 2;
        if(idx==0) break;
        set_union(seg[idx*2].second.begin(), seg[idx*2].second.end(), seg[idx*2+1].second.begin(), seg[idx*2+1].second.end(), inserter(temp_set, temp_set.begin()));
        seg[idx].second.swap(temp_set);
    }
}

int get_sum(int l, int r){
    l += SEG_LEN;
    r += SEG_LEN;
    // int ret = 0;
    set<int> ret;
    set<int> tmp;
    while(l<r){
        if(l%2){
            set_union(ret.begin(), ret.end(), seg[l].second.begin(), seg[l].second.end(), inserter(tmp, tmp.begin()));
            ret.swap(tmp);
            ++l;
        }
        l /= 2;

        if(r%2){
            set_union(ret.begin(), ret.end(), seg[r-1].second.begin(), seg[r-1].second.end(), inserter(tmp, tmp.begin()));
            ret.swap(tmp);
            --r;
        }
        r /= 2;
    }
    return ret.size();
}


int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, q;
    cin >> n >> q;

    seg.resize(SEG_LEN*2);

    rep(i, n){
        int c;
        cin >> c;
        add(i+1, c);
    }


    rep(i, n){
        int l, r;
        cin >> l >> r;

        cout << get_sum(l, r+1) << endl;
    }

    return 0;
}