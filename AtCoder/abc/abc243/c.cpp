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

    unordered_map<int, map<int, char>> mp;
    rep(i, n){
        mp[y[i]][x[i]] = s[i];
    }

    for(auto k: mp){
        int rmn = 1001001001;
        int lmx = 0;

        for(auto x_lr: k.second){
            if(x_lr.second == 'R'){
                if(lmx > x_lr.first){
                    puts("Yes");
                    return 0;
                }

                rmn = min(rmn, x_lr.first);
            }
            else{
                if(rmn < x_lr.first){
                    puts("Yes");
                    return 0;
                }

                lmx = max(lmx, x_lr.first);
            }
        }
    }

    puts("No");



    return 0;
}