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

    pair<int, int> xl[n];
    rep(i, n){
        int x, l;
        cin >> x >> l;

        xl[i] = make_pair(x, l);
    }

    sort(xl, xl+n);
    vector<int> over(n, 0);
    int p_reach = xl[0].first + xl[0].second;
    int over_idx = 0;

    rep1(i, n){
        int x = xl[i].first;
        int l = xl[i].second;

        if(x-l < p_reach){
            ++over[over_idx];
            for(int j = i+1; j < n; ++j) {
                int nx = xl[j].first;
                int nl = xl[j].second;
                
                if(nx - nl < p_reach) ++over[over_idx];
                else break;
            }
        }
    }


    return 0;
}