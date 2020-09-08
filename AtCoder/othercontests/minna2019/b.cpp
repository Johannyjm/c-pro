#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    vector<int> road(4, 0);
    rep(i, 3){
        int a, b;
        cin >> a >> b;
        ++road[a-1];
        ++road[b-1];
    }

    rep(i, 4){
        if(road[i] > 2){
            puts("NO");
            return 0;
        }
    }

    puts("YES");

    return 0;
}