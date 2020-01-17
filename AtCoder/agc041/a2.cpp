#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ll n, a, b;
    cin >> n >> a >> b;

    if(abs(a-b)%2){
        ll step = min(min(a, b) - 1, n - max(a, b));
        cout << step + 1 + (abs(a-b)-1)/2 << endl;;
        return 0;
    }
    cout << abs(a-b) / 2 << endl;

    return 0;
}