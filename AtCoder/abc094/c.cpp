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

    vector<int> x(n), for_med(n);
    rep(i, n) {
        cin >> x[i];
        for_med[i] = x[i];
    }
    
    sort(for_med.begin(), for_med.end());
    int left = for_med[n/2 - 1];
    int right = for_med[n/2];

    rep(i, n){
        if(x[i] <= left) cout << right << endl;
        else if(x[i] >= right) cout << left << endl;
        else raise;
    }
}