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
    rep(i, n) {
        int x, l;
        cin >> x >> l;
 
        xl[i] = make_pair(x, l);
    }
    sort(xl, xl+n);
 
    int res = n;
    int p_reach = xl[0].first + xl[0].second;
    rep1(i, n){
        int x = xl[i].first;
        int l = xl[i].second;
 
        if(x-l < p_reach) {
            --res;
 
        }
        else p_reach = x+l;
    }
    
    cout << res << endl;
 
    return 0;
}