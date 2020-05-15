#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

template <typename T>
class Sum {
public:
    // 単位元
    T unit;

    Sum(void) {
        // 単位元
        unit = 0;
    }

    // 演算関数
    T calc(T a, T b) {
        return a + b; 
    }
};

template <typename T>
struct Min {
public:
    // 単位元
    T unit;

    Min(void) {
        // 単位元
        unit = INF;
    }

    // 演算関数
    T calc(T a, T b) {
        return min(a, b); 
    }
};

template <typename T, class MONOID>
class SegmentTree {
public:
    // セグメント木の葉の要素数
    int n;

    // セグメント木
    vector<T> tree;

    // モノイド
    MONOID mono;

    SegmentTree(vector<T> &v) : n(1 << (int)ceil(log2(v.size()))), tree(vector<T>(n << 1)) {
        for(int i = 0; i < v.size(); ++i) {
            update(i, v[i]);
        }
        for(int i = v.size(); i < n; ++i) {
            update(i, mono.unit);
        }
    }

    // k番目の値(0-indexed)をxに変更
    void update(int k, T x) {
        k += n;
        tree[k] = x;
        for(k = k >> 1; k > 0; k >>= 1){
            tree[k] = mono.calc(tree[k << 1 | 0], tree[k << 1 | 1]);
        }
    }

    // [l, r)の最小値(0-indexed)を求める．
    T query(int l, int r) {
        T res = mono.unit;
        l += n;
        r += n;
        while(l < r) {
            if(l & 1) {
                res = mono.calc(res, tree[l++]);
            }
            if(r & 1) {
                res = mono.calc(res, tree[--r]);
            }
            l >>= 1;
            r >>= 1;
        }
        return res;
    }

    T operator[](int k) {
        // st[i]で添字iの要素の値を返す
        if(k - n >= 0 || k < 0) {
            return -INF;
        }
        return tree[tree.size() - n + k];
    }

    void show(void) {
        int ret = 2;
        for(int i = 1; i < 2*n; ++i) {
            if(tree[i] == mono.unit) cout << "UNIT ";
            else cout << tree[i] << " ";
            if(i == ret - 1) {
                cout << endl;
                ret <<= 1;
            }
        }
        cout << endl;
    }
};

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    vector<int> a(m), b(m);
    rep(i, m){
        cin >> a[i] >> b[i];
        --a[i];
        --b[i];
    }

    vector<int> v(n + 1);
    SegmentTree<int, Sum<int> > st(v);

    // if(query) {
    //     // クエリget(i)の時
    //     scanf("%d", &i);
    //     printf("%d\n", st.query(0, i));

    
    // 私のセグメント木の更新処理は加算ではなく代入なので，
    // これはs - 1番目の値をx足しているのと同義です．
    rep(i, m){
        st.update(a[i] - 1, st[a[i] - 1] + 1);
        st.update(b[i], st[b[i]] - 1);
    }

    

    return 0;
}