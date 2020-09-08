#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    pair<int, int> lim_cost[n];
    rep(i, n){
        int a, b;
        cin >> a >> b;

        lim_cost[i] = make_pair(b, a);
    }
    sort(lim_cost, lim_cost+n);

    int lim;
    int time = 0;
    bool flg = true;

    rep(i, n){
        lim = lim_cost[i].first;
        time += lim_cost[i].second;
        if(time>lim){
            flg = false;
            break;
        }

    }
    if(flg) puts("Yes");
    else puts("No");
}