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

    int diff = 2025 - n;

    rep1(i, 10){
        rep1(j, 10){
            if(i * j == diff){
                cout << i << " x " << j << endl;
            }
        }
    }
}