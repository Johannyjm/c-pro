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
    string res;
    cin >> res;

    if(n%2){
        rep1(i, n){
            string a;
            cin >> a;
            if(i%2) res = res + " " + a;
            else res = a + " " + res;
        }        
    }
    else{
        rep1(i, n){
            string a;
            cin >> a;
            if(i%2) res = a + " " + res;
            else res = res + " " + a;
        }
    }
    cout << res << endl;
}