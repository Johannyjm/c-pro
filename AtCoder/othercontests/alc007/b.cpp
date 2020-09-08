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
    double va, vb, l;
    cin >> n >> va >> vb >> l;

    double current = l;
    rep(_, n){
        double sec = current / va;
        current = vb * sec;
    }

    printf("%.19f\n", current);

    return 0;
}