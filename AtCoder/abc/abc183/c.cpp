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
    vector<vector<int>> t(n, vector<int>(n));
    rep(i, n) rep(j, n) cin >> t[i][j];

    vector<int> order(n);
    rep(i, n) order[i] = i;

    int res = 0;
    do{
        if(order.front() != 0) continue;
        int dist = 0;
        rep1(i, n){
            // cout << t[order[i-1]][order[i]] << endl;
            dist += t[order[i-1]][order[i]];
        }
        dist += t[order.back()][0];
        // cout << dist << endl;
        if(dist == k) ++res;

    } while(next_permutation(order.begin(), order.end()));

    cout << res << endl;

    return 0;
}