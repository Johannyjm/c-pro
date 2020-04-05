#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    vector<int> a(n);
    rep(i, n) cin >> a[i];

    unordered_set<int> generative;
    rep(i, 1<<n){
        int sum = 0;
        rep(j, n){
            if(i & (1<<j)) sum += a[j];
        }
        generative.insert(sum);

    }

    int q;
    cin >> q;
    rep(_, q){
        int m;
        cin >> m;

        if(generative.count(m)) puts("yes");
        else puts("no");
    }

    return 0;
}