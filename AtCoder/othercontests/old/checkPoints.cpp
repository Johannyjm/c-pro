#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

ll m_dist(ll p1[], ll p2[]){
    ll dist = abs(p1[0] - p2[0]) + abs(p1[1] - p2[1]);
    return dist;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    
    ll ab[n][2], cd[m][2];
    rep(i, n) {
        int a, b;
        cin >> a >> b;
        ab[i][0] = a;
        ab[i][1] = b;
    }
    rep(i, m) {
        int c, d;
        cin >> c >> d;
        cd[i][0] = c;
        cd[i][1] = d;
    }
    
    rep(i, n){
        ll min_dist = 1e9;
        int min_idx;

        rep(j, m){
            if(m_dist(ab[i], cd[j]) < min_dist){
                min_dist = m_dist(ab[i], cd[j]);
                min_idx = j;
            }
        }
        cout << min_idx+1 << endl;
    }
    


}