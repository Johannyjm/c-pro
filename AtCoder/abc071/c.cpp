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
    vector<int> a(n);
    map<int, int> num;

    rep(i, n){
        cin >> a[i];
        ++num[a[i]];
    }

    sort(a.begin(), a.end(), greater<int>());

    ll h = 0;
    ll w = 0;
    rep(i, n){
        if(num[a[i]]>1){
            if(h==0) {
                h = a[i];
                num[a[i]] -= 2;
            }
            else if(w==0) w = a[i];
            else if(h && w) break;
        }
    }
    cout << h*w << endl;
}