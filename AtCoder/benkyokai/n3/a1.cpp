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



    vector<pair<char, int>> comp;
    comp.push_back({s.front(), 1});
    rep1(i, n){
        if(comp.back().first == s[i]) comp.back().second++;
        else comp.push_back({s[i], 1});
    }

    int res1 = 0;
    int res2 = 0;
    for(auto e: comp){
        if(e.first == 'L') res1 += e.second - 1;
        else res2 += e.second - 1;
    }

    int gain1 = 0;
    int gain2 = 0;
    for(auto e: comp)

    return 0;
}