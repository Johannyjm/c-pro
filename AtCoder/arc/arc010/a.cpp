#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;
const ll INF = 1LL << 60;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, m, a, b;
    cin >> n >> m >> a >> b;

    int current = n;

    rep1(i, m+1){
        int c;
        cin >> c;
        
        if(current <= a) current += b;

        if(c>current){
            cout << i << endl;
            return 0;
        }

        current -= c;

    }

    cout << "complete" << endl;

    return 0;
}