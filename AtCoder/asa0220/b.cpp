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

    int current_max;
    cin >> current_max;

    rep1(i, n){
        int h;
        cin >> h;

        if(current_max-1 > h){
            puts("No");
            return 0;
        }

        current_max = max(current_max, h);
    }

    puts("Yes");

    return 0;
}