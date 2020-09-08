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

    map<int, int> num;
    vector<int> A(n);
    rep(i, n){
        int a;
        cin >> a;
        ++num[a];
        A[i] = a;
    }

    int res = 0;
    rep(i, n){
        if(num[A[i]] % 2) {
            ++res;
            ++num[A[i]];
        }
    }
    cout << res << endl;
}