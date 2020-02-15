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
    vector<int> res(6, 0);

    rep(i, n){
        double maxT, minT;
        cin >> maxT >> minT;

        if(35<=maxT) ++res[0];
        if(30<=maxT && maxT<35) ++res[1];
        if(25<=maxT && maxT<30) ++res[2];
        if(25<=minT) ++res[3];
        if(minT<0 && 0<=maxT) ++res[4];
        if(maxT<0) ++res[5];
    }

    rep(i, 5) cout << res[i] << " ";
    cout << res[5] << endl;

    return 0;
}