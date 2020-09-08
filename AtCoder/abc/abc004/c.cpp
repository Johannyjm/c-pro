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

    int num[] = {1, 2, 3, 4, 5, 6};
    int m = n%30;
    int cnt = 0;
    rep(_, 6){
        rep(i, 5){
            ++cnt;
            int tmp = num[i];
            num[i] = num[i+1];
            num[i+1] = tmp;

            if(cnt == m){
                rep(j, 6) cout << num[j];
                cout << endl;
                return 0;
            }
        }
    }

    return 0;
}