#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    ll A, B, C, X, Y;
    cin >> A >> B >> C >> X >> Y;
    ll res = 0;

    if(A + B > C * 2){
        res += C * min(X, Y) * 2;

        if(X > Y){

            if(X > C * 2) res += C * 2 * (X - Y);
            else res += A * (X - Y);
        }
        if(X < Y){
            if(Y > C * 2) res += C * 2 * (Y - X);
            else res += B * (Y - X);
        }
    }
    else res = A * X + B * Y;

    cout << res << endl;
}