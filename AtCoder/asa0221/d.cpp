#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;
const ll INF = 1LL << 60;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ll n, m;
    cin >> n >> m;

    ll start = m/n;
    while(start > 1){
        int mod = m%start;
        if(mod%start==0){
            break;
        }
        --start;
    }

    cout << start << endl;

    return 0;
}