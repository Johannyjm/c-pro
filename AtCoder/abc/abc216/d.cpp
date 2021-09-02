#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    vector<int> k(m);
    vector<vector<int>> a(m);
    rep(i, m){
        cin >> k[i];
        vector<int> aa(k[i]);
        rep(j, k[i]) cin >> aa[j];
        reverse(aa.begin(), aa.end());
        a[i] = aa;
    }

    vector<int> colors(n+1, -1);
    vector<int> remidx;
    rep(i, m){
        if(colors[a[i].back()] != -1){
            remidx.push_back(i);
            remidx.push_back(colors[a[i].back()]);
        }
        else colors[a[i].back()] = i;
    }

    while(!remidx.empty()){
        vector<int> nremidx;
        while(!remidx.empty()){
            int idx = remidx.back();
            remidx.pop_back();
            if(!a[idx].empty()) a[idx].pop_back();
            else continue;

            if(colors[a[idx].back()] != -1){
                nremidx.push_back(idx);
                nremidx.push_back(colors[a[idx].back()]);
            }
            else{
                colors[a[idx].back()] = idx;
            }
        }
        remidx = nremidx;
    }

    rep(i, m){
        if(!a[i].empty()){
            puts("No");
            return 0;
        }
    }

    puts("Yes");


    return 0;
}