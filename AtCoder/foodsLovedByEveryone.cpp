#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    int bucket[m] = {0};

    rep(i, n){
        int k;
        cin >> k;

        rep(j, k){
            int a;
            cin >> a;
            ++bucket[a-1];
        }
    }

    int res = 0;
    rep(i, m){
        if(bucket[i]==n) ++res;
    }
    cout << res << endl;
}