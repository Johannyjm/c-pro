#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

template<typename T>
vector<T> compress(vector<T> &a){
    vector<T> ret = a;
    sort(ret.begin(), ret.end());
    ret.erase(unique(ret.begin(), ret.end()), ret.end());
    for(int i = 0; i < (int)a.size(); ++i){
        a[i] = lower_bound(ret.begin(), ret.end(), a[i]) - ret.begin();
    }
    return ret;
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<int> a(n), b(n), c(n), d(n), e(n);
    map<int, int> cnta, cntb, cntc, cntd, cnte;
    rep(i, n){
        cin >> a[i] >> b[i] >> c[i] >> d[i] >> e[i];
    }

    vector<int> ao = a;
    vector<int> bo = b;
    vector<int> co = c;
    vector<int> d0 = d;
    vector<int> eo = e;
    

    compress(a);
    compress(b);
    compress(c);
    compress(d);
    compress(e);

    rep(i, n){
        ++cnta[a[i]];
        ++cntb[b[i]];
        ++cntc[c[i]];
        ++cntd[d[i]];
        ++cnte[e[i]];
    }


    int res = 0;
    rep(i, n) rep(j, n){
        if(i >= j) continue;
        int mnmx = min({max(ao[i], ao[j]), max(bo[i], bo[j]), max(co[i], co[j]), max(d0[i], d0[j]), max(eo[i], eo[j])});
        int mnmxcom = min({max(a[i], a[j]), max(b[i], b[j]), max(c[i], c[j]), max(d[i], d[j]), max(e[i], e[j])});
        cout << i << " " << j << ": " << mnmx << endl;
        if(mnmx == max(ao[i], ao[j])){
            if(cnta[mnmxcom+1] > 0){
                res = max(res, mnmx);
            }
        } 
        if(mnmx == max(bo[i], bo[j])){
            if(cntb[mnmxcom+1] > 0){
                res = max(res, mnmx);
            }
        }
        if(mnmx == max(co[i], co[j])){
            if(cntc[mnmxcom+1] > 0){
                res = max(res, mnmx);
            }
        }
        if(mnmx == max(d0[i], d0[j])){
            if(cntd[mnmxcom+1] > 0){
                res = max(res, mnmx);
            }
        }
        if(mnmx == max(eo[i], eo[j])){
            if(cnte[mnmxcom+1] > 0){
                res = max(res, mnmx);
            }
        }
        
    }

    cout << res << endl;

    return 0;
}