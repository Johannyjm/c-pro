#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    string s;
    cin >> s;
    int n = s.size();
    ll k;
    cin >> k;

    vector<pair<char, int>> comp;
    comp.push_back({s[0], 1});
    rep1(i, n){
        if(comp.back().first == s[i]){
            ++comp.back().second;
        }
        else comp.push_back({s[i], 1});
    }

    string s2 = s+s;
    int n2 = s2.size();
    vector<pair<char, int>> comp2;
    comp2.push_back({s2[0], 1});
    rep1(i, n2){
        if(comp2.back().first == s2[i]){
            ++comp2.back().second;
        }
        else comp2.push_back({s2[i], 1});
    }

    // for(auto e: comp2) cout << e.first << " " << e.second << endl;

    string s3 = s+s+s;
    int n3 = s3.size();

    vector<pair<char, int>> comp3;
    comp3.push_back({s3[0], 1});
    rep1(i, n3){
        if(comp3.back().first == s3[i]){
            ++comp3.back().second;
        }
        else comp3.push_back({s3[i], 1});
    }

    string s4 = s+s+s+s;
    int n4 = s4.size();

    vector<pair<char, int>> comp4;
    comp4.push_back({s4[0], 1});
    rep1(i, n4){
        if(comp4.back().first == s4[i]){
            ++comp4.back().second;
        }
        else comp4.push_back({s4[i], 1});
    }

    ll cnt[4] = {};
    for(auto e: comp){
        if(e.second >= 2) cnt[0] += e.second/2;
    }

    for(auto e: comp2){
        if(e.second >= 2) cnt[1] += e.second/2;
    }

    for(auto e: comp3){
        if(e.second >= 2) cnt[2] += e.second/2;
    }

    for(auto e: comp4){
        if(e.second >= 2) cnt[3] += e.second/2;
    }

    if(k<=4){
        cout << cnt[k-1] << endl;
        return 0;
    }

    ll res;
    if(k%2==1){
        ll gain = cnt[2]-cnt[0];
        res = gain*(k-3)/2 + cnt[2];
    }
    else{
        ll gain = cnt[3]-cnt[1];
        res = gain*(k-4)/2 + cnt[3];
    }

    cout << res << endl;

    return 0;
}