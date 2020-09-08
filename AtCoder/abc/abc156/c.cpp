#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;
const ll INF = 1LL << 60;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<int> x(n);

    int n_min = 101;
    int n_max = -1;
    rep(i, n){
        int tmp;
        cin >> tmp;
        x[i] = tmp;
        n_min = min(n_min, tmp);
        n_max = max(n_max, tmp);
    }

    int d_min = 300000;
    for(int i = n_min; i <= n_max; ++i){
        int dist = 0;
        rep(j, n){
            dist += (i - x[j]) * (i - x[j]);
        }
        d_min = min(d_min, dist);
    }

    cout << d_min << endl;

    return 0;
}