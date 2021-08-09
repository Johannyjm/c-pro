#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<pair<int, int>> a(n);
    rep(i, n){
        int aa;
        cin >> aa;
        a[i] = {aa, i};
    }

    sort(a.begin(), a.end(), greater<pair<int, int>>());

    cout << a[1].second + 1 << endl;

    return 0;
}