#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    vector<int> cand;
    map<int, int> one;
    map<int, int> two;

    rep(i, m){
        int a, b;
        cin >> a >> b;

        if(a==1) {
            ++one[b];
            cand.push_back(b);
        }
        if(b==n) ++two[a];
    }

    for (int num: cand){
        if(two[num] > 0){
            puts("POSSIBLE");
            return 0;
        }
    }

    puts("IMPOSSIBLE");
    return 0;
}