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

    vector<int> x(n), y(n);
    rep(i, n) cin >> x[i] >> y[i];

    string s;
    cin >> s;

    compress(y);

    vector<pair<int, int>> mnmx(220000, pair<int, int>(1001001001, 0));
    rep(i, n){
        
        if(s[i] == 'R'){
            mnmx[y[i]].
        }

        if(s[i] == 'R'){
            mnmx[y[i]].first = min(mnmx[y[i]].first, x[i]);
        }
        else{
            mnmx[y[i]].second = max(mnmx[y[i]].second, x[i]);
        }
    }



    return 0;
}