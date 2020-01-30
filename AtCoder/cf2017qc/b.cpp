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
    int even = 0;
    rep(_, n){
        int a;
        cin >> a;
        if(a%2==0) ++even;
    }

    int all_odd = pow(2, even);
    cout << pow(3, n) - all_odd << endl;

    return 0;
}