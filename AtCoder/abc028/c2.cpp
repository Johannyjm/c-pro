#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int num[5];
    rep(i, 5) cin >> num[i];

    vector<int> mul;
    do{
        mul.push_back(num[0] + num[1] + num[2]);
        rep(i, 5) cout << num[i] << " ";
        cout << endl;
    }while(next_permutation(num, num+5));

    sort(mul.begin(), mul.end(), greater<int>());

    rep(i, 10) cout << mul[i] << " ";
    cout << endl;
    cout << mul[2] << endl;
}