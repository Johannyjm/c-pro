#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ll a, b, c;
    cin >> a >> b >> c;

    if(a == b){
        cout << "=" << endl;
        return 0;
    }

    if(a * b == 0){
        if(a + b > 0){
            if(a > b) cout << ">" << endl;
            else cout << "<" << endl;
        }
        else{
            if(c%2 == 0){
                if(a == 0) cout << "<" << endl;
                else cout << ">" << endl;
            }
            else{
                if(a == 0) cout << ">" << endl;
                else cout << "<" << endl;
            }
        }
        return 0;
    }

    if(a > 0 && b > 0){
        if(a == b) cout << "=" << endl;
        else if(a > b) cout << ">" << endl;
        else cout << "<" << endl;

        return 0;
    }

    if(a * b < 0){
        if(c%2 == 0){
            if(b < 0){
                if(a == -b) cout << "=" << endl;
                else if(a > -b) cout << ">" << endl;
                else cout << "<" << endl;
            }
            else{
                if(-a == b) cout << "=" << endl;
                else if(-a > b) cout << ">" << endl;
                else cout << "<" << endl;
            }
            return 0;
        }
        else{
            if(a > 0) cout << ">" << endl;
            else if(b > 0) cout << "<" << endl;

            return 0;
        }
    }

    if(c%2 == 0){
        if(a > b) cout << "<" << endl;
        else cout << ">" << endl;
    }
    else{
        if(a > b) cout << ">" << endl;
        else cout << "<" << endl;
    }

    return 0;
}