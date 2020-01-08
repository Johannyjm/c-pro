#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, t;
    cin >> n >> t;

    int prev;
    cin >> prev;
    int res = 0;
    int begin = prev;
    int end = prev + t;

    rep1(i, n){
        int next;
        cin >> next;

        if(next-prev <= t) end = next + t;
        else {
            res += end - begin;
            begin = next;
            end = next + t;
        }
        prev = next;
    }
    res += end - begin;
    cout << res << endl;
}