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

    int days = 0;
    int sum = 0;
    rep(i, 7*n){
        int a;
        cin >> a;

        sum += a;
        ++days;

        if(days == 7){
            cout << sum << " ";
            days = 0;
            sum = 0;
        }
    }

    cout << endl;

    return 0;
}