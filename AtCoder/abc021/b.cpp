#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, a, b, k;
    cin >> n >> a >> b >> k;

    int bucket[100] = {0};
    ++bucket[a-1];
    ++bucket[b-1];

    rep(i, k){
        int p;
        cin >> p;

        if(bucket[p-1]){
            cout << "NO" << endl;
            return 0;
        }
        ++bucket[p-1];
    }
    cout << "YES" << endl;
}