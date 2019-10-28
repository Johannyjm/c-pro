#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int A, B, C, X, Y;
    cin >> A >> B >> C >> X >> Y;
    int res = 0;

    if(A + B > C * 2){

        if(X > Y){

            if(X > C * 2) res = C * 2 * X;
            else res = A * (X - Y) + C * 2 * Y;

        }

        else{

            if(Y > C * 2) res = C * 2 * Y;
            else res = B * (Y - X) + C * 2 * X;

        }
    }
    else res = A * X + B * Y;

    cout << res << endl;
}
