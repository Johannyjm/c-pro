#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;
const ll INF = 1LL << 60;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, k;
    cin >> n >> k;

    int one, two;
    cin >> one >> two;
    rep(i, n-2){
        int three;
        cin >> three;
        if(one+two+three < k){
            cout << i+3 << endl;
            return 0;
        }
        one = two;
        two = three;
    }

    cout << -1 << endl;

    return 0;
}