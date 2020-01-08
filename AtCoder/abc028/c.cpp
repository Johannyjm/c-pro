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
    for (int i = 0; i < 3; ++i){
        for (int j = i+1; j < 4; ++j){
            for (int k = j+1; k < 5; ++k){
                mul.push_back(num[i] + num[j] + num[k]);
            }
        }
    }

    sort(mul.begin(), mul.end());

    cout << mul[7] << endl;
}