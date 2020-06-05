#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    vector<int> r(n);
    rep(i, n) cin >> r[i];

    // up down up down...
    int res1 = 0;
    int prev = r[0];
    int flip = 1;
    rep1(i, n){
        int curr = r[i];
        if(i%2==flip && prev<=curr){
            ++res1;
            flip = 1 - flip;
        }

        else if(i%2==(1-flip) && prev>=curr){
            ++res1;
            flip = 1 - flip;
        }

        prev = curr;
    }

    // down up down up...
    int res2 = 0;
    prev = r[0];
    flip = 1;
    rep1(i, n){
        int curr = r[i];
        if(i%2==flip && prev>=curr){
            ++res2;
            flip = 1 - flip;
        }

        else if(i%2==(1-flip) && prev<=curr){
            ++res2;
            flip = 1 - flip;
        }

        prev = curr;
    }

    int drop = min(res1, res2);
    
    if(n-drop < 3) cout << 0 << endl;
    else cout << n - drop << endl;

    return 0;
}