#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

P f(int n){
    string num = to_string(n);
    int a = num[0] - '0';
    int b = num[num.length()-1] - '0';

    return make_pair(a, b);
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    map<P, int> freq;
    rep1(i, n+1){
        ++freq[f(i)];
    }

    int res = 0;
    rep1(i, n+1){
        P p = f(i);
        int a = p.first;
        int b = p.second;

        res += freq[make_pair(b, a)];
    }

    cout << res << endl;

    return 0;
}