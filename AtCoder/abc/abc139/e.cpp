#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(n-1));
    rep(i, n) rep(j, n-1){
        cin >> a[i][j];
        --a[i][j];
    }

    vector<vector<int>> cnv(n, vector<int>(n, -1));
    int ptr = 0;
    rep(i, n) rep(j, n){
        if(i >= j) continue;
        cnv[i][j] = ptr;
        cnv[j][i] = ptr;
        ++ptr;
    }
    rep(i, n){
        rep(j, n) cout << cnv[i][j] << " ";
        cout << endl;
    }

    vector<vector<int>> g(n*(n-1)/2), parent(n*(n-1)/2);
    rep(i, n){
        rep(j, n-2){
            int from = cnv[i][a[i][j]];
            int to = cnv[i][a[i][j+1]];

            g[from].push_back(to);
            parent[to].push_back(from);
        }
    }

    queue<int> q;
    rep(i, n*(n-1)/2){
        cout << i << " ";
        for(auto nv: g[i]) cout << nv << " ";
        cout << endl;
    }
    cout << endl;
    rep(i, n*(n-1)/2){
        cout << i << " ";
        for(auto nv: parent[i]) cout << nv << " ";
        cout << endl;
    }


    return 0;
}