#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, k;
    cin >> n >> k;
    vector<int> a(n), b(n);
    rep(i, n) cin >> a[i];
    rep(i, n) cin >> b[i];

    vector<int> cand;
    cand.push_back(a.front());
    cand.push_back(b.front());

    rep1(i, n){
        vector<int> tmp;
        if(cand.size() == 0){
            puts("No");
            return 0;
        }
        bool flga = false;
        bool flgb = false;
        for(auto e: cand){
            if(abs(e - a[i]) <= k) flga = true;
            if(abs(e - b[i]) <= k) flgb = true;

        }


        if(flga) tmp.push_back(a[i]);
        if(flgb) tmp.push_back(b[i]);

        cand = tmp;
    }

    if(cand.size() == 0) puts("No");
    else puts("Yes");

    return 0;
}