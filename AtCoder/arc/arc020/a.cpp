#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;
const ll INF = 1LL << 60;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int a, b;
    cin >> a >> b;

    if(abs(a) <= abs(b)){
        if(abs(a) == abs(b)) puts("Draw");
        else puts("Ant");
    }
    else puts("Bug");

    return 0;
}