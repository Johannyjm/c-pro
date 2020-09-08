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

    int num = n%9 + 9 * (n%9==0);
    int repeat = n/9 + 1*(n%9!=0);
    rep(i, repeat){
        cout << num;
    }
    cout << endl;

    return 0;
}