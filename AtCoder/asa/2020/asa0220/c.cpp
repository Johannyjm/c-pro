#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;
const ll INF = 1LL << 60;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, a, b;
    cin >> n;

    vector<pair<int, int>> ba(n);
    rep(i, n){
        cin >> a >> b;
        ba[i] = make_pair(b, a);
    }

    sort(ba.begin(), ba.end());

    int time = 0;
    rep(i, n){
        b = ba[i].first;
        a = ba[i].second;

        time += a;
        if(time > b){
            puts("No");
            return 0;
        }
    }
    
    puts("Yes");

    return 0;
}