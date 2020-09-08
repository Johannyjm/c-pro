#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;
const ll INF = 1LL << 60;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    vector<int> cd(n);
    rep(i, n+1) cd[i] = i+1;

    int current = 0;
    rep(i, m){
        int d;
        cin >> d;

        rep(j, n){
            if(cd[j]==d){
                cd[j] = current;
                current = d;
                break;
            }
        }
    }

    rep(i, n) cout << cd[i] << endl;

    return 0;
}