#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    int cnt = 0;
    int bugsum = 0;

    rep(i, n){
        int a;
        cin >> a;
        if(a){
            ++cnt;
            bugsum += a;
        }
    }

    cout << bugsum/cnt + (bugsum%cnt!=0) << endl;
}