#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

int n, k;
vector<int> a;
bool check(int m){
    vector<pair<int, int>> cnt;
    cnt.push_back({a.front(), 1});
    rep1(i, n){
        if(cnt.back().first == a[i]) ++cnt.back().second;
        else cnt.push_back({a[i], 1});
    }
    int sm = 0;
    for(auto e: cnt) sm += e.second / (m+1);

    return sm <= k;
}


int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n >> k;
    a.resize(n);
    rep(i, n) cin >> a[i];

    int ok = 220000;
    int ng = 0;
    while(ok - ng > 1){
        int mid = (ok + ng) / 2;

        if(check(mid)) ok = mid;
        else ng = mid;
    }

    cout << ok << endl;

    return 0;
}