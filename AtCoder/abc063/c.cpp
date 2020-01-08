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

    int ten_sum = 0;
    int other_sum = 0;
    int other_min = 101;

    rep(i, n){
        int s;
        cin >> s;
        if(s%10) {
            other_sum += s;
            other_min = min(other_min, s);
        }
        else {
            ten_sum += s;
        }
    }

    if((ten_sum + other_sum)%10) cout << ten_sum + other_sum << endl;
    else{
        if(other_sum){
            cout << ten_sum + other_sum - other_min << endl;
        }
        else{
            cout << 0 << endl;
        }
    }



}