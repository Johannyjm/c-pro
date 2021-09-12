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
    string s;
    cin >> s;

    vector<pair<char, int>> comp; // 0: L, 1: R
    comp.push_back({s.front(), 1});

    rep1(i, n){
        if(comp.back().first == s[i]) ++comp.back().second;
        else comp.push_back({s[i], 1});
    }

    // for(auto e: comp) cout << e.first << " " << e.second << endl;
    
    // L to R
    vector<pair<int, int>> ls;
    rep(i, (int)comp.size()){
        if(comp[i].first == 'L') ls.push_back({comp[i].second, i});
    }

    sort(ls.begin(), ls.end(), greater<pair<int, int>>());

    vector<pair<char, int>> tmp = comp;
    rep(i, k){
        tmp[ls[i].second].first = 'R';
    }

    vector<pair<char, int>> comp1;
    comp1.push_back(tmp.front());
    rep1(i, (int)tmp.size()){
        if(comp1.back().first == tmp[i].first) comp1.back().second += tmp[i].second;
        else comp1.push_back(tmp[i]);
    }

    ll res = 0;
    for(auto e: comp1){
        if(e.first != 'R') continue;

        res += e.second - 1;
    }

    // R to L
    vector<pair<int, int>> rs;
    rep(i, (int)comp.size()){
        if(comp[i].first == 'R') rs.push_back({comp[i].second, i});
    }

    sort(rs.begin(), rs.end(), greater<pair<int, int>>());

    tmp = comp;
    rep(i, k){
        tmp[rs[i].second].first = 'L';
    }

    vector<pair<char, int>> comp2;
    comp2.push_back(tmp.front());
    rep1(i, (int)tmp.size()){
        if(comp2.back().first == tmp[i].first) comp2.back().second += tmp[i].second;
        else comp2.push_back(tmp[i]);
    }

    ll res2 = 0;
    for(auto e: comp2){
        if(e.first != 'L') continue;

        res2 += e.second - 1;
    }

    cout << max(res2, res) << endl;

    return 0;
}