#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;
const ll INF = 1LL << 60;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ll h, w;
    cin >> h >> w;

    if(h%3==0 || w%3==0) {
        cout << 0 << endl;
        return 0;
    }

    if(h%2==0 && w%2==1){
        ll s_max = h*(w/2);
        ll s_min = (h/2)*((w+1)/2);
        cout << s_max - s_min << endl;
        return 0;
    }

    if(h%2==1 && w%2==0){
        ll s_max = w*(h/2);
        ll s_min = (w/2)*((h+1)/2);
        cout << s_max - s_min << endl;
        return 0;
    }

    if(h%2==1 && w%2==1){
        ll s_max1 = h*(w/2);
        ll s_max2 = w*(h/2);
        ll s_min1 = (h/2)*((w+1)/2);
        ll s_min2 = (w/2)*((h+1)/2);
        cout << min(s_max1-s_min1, s_max2-s_min2) << endl;
        return 0;
    }

    cout << h*w/2 - h*w/4 << endl;

    return 0;
}